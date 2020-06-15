#ifndef DNAPARSER_H
#define DNAPARSER_H

#include <vector>
#include <string>
#include <rapidjson/include/rapidjson/document.h>

class DNAParser
{
public:
    DNAParser();

    std::vector<std::string> parse(rapidjson::Value &value);

};

#endif // DNAPARSER_H
