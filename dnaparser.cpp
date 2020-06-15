#include "dnaparser.h"
#include <iostream>

DNAParser::DNAParser()
{

}

std::vector<std::string> DNAParser::parse(rapidjson::Value &value)
{
    std::vector<std::string> result;

    std::cout << value.IsArray() << std::endl;
    std::cout << value.IsObject() << std::endl;
    std::cout << value.GetType() << std::endl;
    std::cout << value.HasMember("dna") << std::endl;
    rapidjson::Value &dna = value["dna"];

    for (auto &row: dna.GetArray()) {
        result.push_back(std::string(row.GetString()));
    }

    return result;
}
