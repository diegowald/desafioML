#include "statisticsparser.h"

#include <rapidjson/include/rapidjson/document.h>
#include <rapidjson/include/rapidjson/stringbuffer.h>
#include <rapidjson/include/rapidjson/writer.h>

StatisticsParser::StatisticsParser()
{

}

std::string StatisticsParser::toJsonString(StatisticsCalculator &stats)
{
    rapidjson::Document doc;
    rapidjson::Document::AllocatorType &allocator = doc.GetAllocator();
    doc.SetObject();

    addValueMember<unsigned long>(doc, "count_mutant_dna", static_cast<unsigned long>(stats.mutantCount()), allocator);
    addValueMember<unsigned long>(doc, "count_human_dna", static_cast<unsigned long>(stats.humanCount()), allocator);
    addValueMember<double >(doc, "ratio", stats.ratio(), allocator);
    rapidjson::StringBuffer stringBuffer;
    rapidjson::Writer<rapidjson::StringBuffer> writer(stringBuffer);
    doc.Accept(writer);

    std::string result(stringBuffer.GetString());
    return result;
}
