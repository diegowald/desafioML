#ifndef DNAANALYZER_H
#define DNAANALYZER_H

#include <string>
#include <vector>

class DNAAnalyzer
{
public:
    DNAAnalyzer();
    
    void chain(const std::string &value, std::size_t chromosomeLength);
    void chain(const std::vector<std::string> &dna);
    
    std::string chainAsString() const;
    std::vector<std::string> chain() const;
    
    void repetitionLength(std::size_t value);
    std::size_t repetitionLength() const;
    
    bool isMutant() const;
    
private:
    std::string extract(std::size_t startPosition, int separation);
    bool compare(const std::string &element);
    
    bool extractAndCompare(std::size_t startPosition, std::size_t separation) const;
private:
    std::string _chain;
    std::size_t _dnaLength;
    std::size_t _chromosomeLength;
    std::size_t _repetitionLength;
};

#endif // DNAANALYZER_H
