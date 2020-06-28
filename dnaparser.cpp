#include "dnaparser.h"

DNAParser::DNAParser()
{

}

std::vector<std::string> DNAParser::parse(rapidjson::Value &value)
{
    std::vector<std::string> result;

    rapidjson::Value &dna = value["dna"];

    for (auto &row: dna.GetArray()) {
        result.push_back(std::string(row.GetString()));
    }

    return result;
}
