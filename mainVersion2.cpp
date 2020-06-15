#include <iostream>
#include <vector>
#include <string>

#include <served/served.hpp>
#include <served/plugins.hpp>

#include <rapidjson/include/rapidjson/document.h>

#include "dnaanalyzer.h"
#include "dnaparser.h"



int main()
{
/*    std::vector<std::string> dna {"ATGCGA","CAGTGC","TTATGT","AGAAGG","CCCCTA","TCACTG"};

    DNAAnalyzer dnaAnalyzer;
    dnaAnalyzer.chain(dna);
    dnaAnalyzer.repetitionLength(4);
    bool result = dnaAnalyzer.isMutant();
    std::cout << "isMutant: " << (result ? "true" : "false") << std::endl;
    return 0;
*/

    served::multiplexer mux;
    mux.use_after(served::plugin::access_log);

    std::string address = "127.0.0.1";
    std::string port = "34125";
    int numThreads = 10;

    mux.handle("/mutant").post([](served::response &res, const served::request &req) {
        std::string body = req.body();
        int status/* = 400*/;
        if (body.size() > 0) {
            rapidjson::Document d;
            std::cout << body << std::endl;
            d.Parse(body.c_str());
            if (d.HasParseError()) {
                status = 400;
            } else {
                std::cout << d.HasParseError() << std::endl;
                DNAParser parser;
                std::vector<std::string> dna = parser.parse(d);
                DNAAnalyzer analyzer;
                analyzer.chain(dna);
                analyzer.repetitionLength(4);
                status = analyzer.isMutant() ? 200 : 403;
                // res.set_status(403); // Forbidden
                // res.set_status(200); // OK
            }
        } else {
            status = 400; // Invalid request
        }
        res.set_status(status);
    });

    /*
    setup(d, resolvers, address, port, numThreads, mux);

    cout << "Starting Service" << endl;
*/

    served::net::server server(address, port, mux);
    server.run(numThreads);
}
