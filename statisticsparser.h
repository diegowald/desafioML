#ifndef STATISTICSPARSER_H
#define STATISTICSPARSER_H

#include <string>
#include "statisticscalculator.h"
#include <rapidjson/include/rapidjson/document.h>

class StatisticsParser
{
public:
    StatisticsParser();

    std::string toJsonString(StatisticsCalculator &stats);

private:
    template <typename T>
    void addValueMember(rapidjson::Value &obj, const std::string &key, T value, rapidjson::Document::AllocatorType &allocator)
    {
        rapidjson::Value k;
        k.SetString(key.c_str(), key.length(), allocator);
        obj.AddMember(k, value, allocator);
    }
};

#endif // STATISTICSPARSER_H
