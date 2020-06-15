#include <iostream>
#include <vector>
#include <string>

#include <served/served.hpp>
#include <served/plugins.hpp>

#include <rapidjson/include/rapidjson/document.h>

#include "dnaanalyzer.h"
#include "dnaparser.h"

#include "database.hpp" // create_database

#include "DTO.h"
#include "DTO-odb.hxx"
#include "statisticscalculator.h"
#include "statisticsparser.h"

unsigned long create(std::shared_ptr<DNA> e)
{
    std::string user = "postgres";
    std::string password = "123";
    std::string dbName = "postgres";
    std::string host = "127.0.0.1";
    std::string port = "5432";

    unsigned long id;
    try
    {
        std::unique_ptr<odb::database> db (create_database(user, password, dbName, host, port));
        //
        {
            odb::transaction t (db->begin ());
            id = db->persist (*e);
            t.commit ();
        }
    }
    catch (const odb::exception& e)
    {
        std::cout << e.what () << std::endl;
        //return 1;
        id = 0;
    }
    return id;
};

int main()
{
    served::multiplexer mux;
    mux.use_after(served::plugin::access_log);

    std::string address = "127.0.0.1";
    std::string port = "34125";
    int numThreads = 1000;

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
                bool isMutant = analyzer.isMutant();
                status = isMutant ? 200 : 403;
                // res.set_status(403); // Forbidden
                // res.set_status(200); // OK

                std::shared_ptr<DNA> element = std::make_shared<DNA>();
                element->chain(analyzer.chainAsString());
                element->isMustant(isMutant);
                create(element);
            }
        } else {
            status = 400;
        }
        res.set_status(status);
    });

    mux.handle("/stats").get([](served::response &res, const served::request &req) {
        (void) req;
        std::string user = "postgres";
        std::string password = "123";
        std::string dbName = "postgres";
        std::string host = "127.0.0.1";
        std::string port = "5432";

        std::string result{};

        try
        {
            std::unique_ptr<odb::database> db (create_database(user, password, dbName, host, port));
            //
            {
                odb::transaction t (db->begin ());
                odb::result<Statistics> r(db->query<Statistics>());
                t.commit ();
                unsigned long long mutantCount = 0;
                unsigned long long humanCount = 0;
                if (r.size() > 0) {
                    for (auto row: r) {
                        if (row.isMutant) {
                            mutantCount = row.quantity;
                        } else {
                            humanCount = row.quantity;
                        }
                    }
                }
                StatisticsCalculator sc(mutantCount, humanCount);
                StatisticsParser sp;
                result = sp.toJsonString(sc);
            }
        }
        catch (const odb::exception& e)
        {
            std::cout << e.what () << std::endl;
        }

        res << result;
    });

    served::net::server server(address, port, mux);
    server.run(numThreads);
}
