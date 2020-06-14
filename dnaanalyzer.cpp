#include "dnaanalyzer.h"
#include <iostream>

DNAAnalyzer::DNAAnalyzer() : _chain(""), _dnaLength(0), _chromosomeLength(0), _repetitionLength(0)
{
}


void DNAAnalyzer::chain(const std::string &value, std::size_t chromosomeLength)
{
    _chain = value;
    _chromosomeLength = chromosomeLength;
    _dnaLength = _chain.length() / chromosomeLength;
}

void DNAAnalyzer::chain(const std::vector<std::string> &dna)
{
    _chain.clear();
    for (auto s: dna) {
        _chain += s;
    }
    _chromosomeLength = dna[0].length();
    _dnaLength = dna.size();
}

std::string DNAAnalyzer::chainAsString() const
{
    return _chain;
}

std::vector<std::string> DNAAnalyzer::chain() const
{
    std::vector<std::string> result;
    for (std::size_t i = 0; i < _dnaLength; ++i) {
        result.push_back(_chain.substr(_chromosomeLength * (i - 1), _chromosomeLength));
    }
    return result;
}


void DNAAnalyzer::repetitionLength(std::size_t value)
{
    _repetitionLength = value;
}

std::size_t DNAAnalyzer::repetitionLength() const
{
    return _repetitionLength;
}

std::string DNAAnalyzer::extract(std::size_t startPosition, int separation)
{
    std::string result {""};

    int position = startPosition;

    std::size_t chainLength = _chain.length();
    std::size_t positionColumn = position % _chromosomeLength;

    for (std::size_t i = 0; i < _repetitionLength && static_cast<std::size_t>(position) < chainLength; ++i)
    {
        if ((position >= 0) && (static_cast<std::size_t>(position) < chainLength) && (static_cast<std::size_t>(position) % _chromosomeLength < positionColumn)) {
            result += _chain[position];
            position += separation;
        }
    }

    return result;
}


bool DNAAnalyzer::compare(const std::string &element)
{
    bool result = true;
    for (std::size_t i = 1; i < element.length(); ++i) {
        if (element[i] != element[i-1]) {
            result = false;
            break;
        }
    }
    return result;
}


bool DNAAnalyzer::extractAndCompare(std::size_t startPosition, std::size_t separation) const
{
    bool result = true;
    int position = startPosition;

    std::size_t chainLength = _chain.length();
    std::size_t positionColumn = position % _chromosomeLength;

    unsigned char lastValue = _chain[position];
    position += separation;
    unsigned char currentValue;
    for (std::size_t i = 1; i < _repetitionLength /*&& static_cast<std::size_t>(position) < chainLength*/; ++i)
    {
        std::cout << "i: " << i << ". position: " << position << std::endl;
        std::cout << "chainLength: " << chainLength << ". chromosome Length: " << static_cast<std::size_t>(position) % _chromosomeLength << std::endl;
        std::cout << "positionColumn: " << positionColumn << std::endl;
        if ((position >= 0) && (static_cast<std::size_t>(position) < chainLength) && (static_cast<std::size_t>(position) % _chromosomeLength >= positionColumn)) {
            std::cout << "last: " << lastValue << ", current: " << currentValue << std::endl;
            currentValue = _chain[position];
            if (lastValue != currentValue) {
                result = false;
                break;
            }
            lastValue = currentValue;
            position += separation;
        } else {
            result = false;
            break;
        }
    }

    return result;
}


bool DNAAnalyzer::isMutant() const
{
    int countRepeated = 0;
    for (std::size_t pos = 0; pos < _chain.length(); ++pos) {
        // check horizontally
        countRepeated += extractAndCompare(pos, 1) ? 1 : 0;
        if (countRepeated == 2) {
            return true;
        }
        // check vertically
        countRepeated += extractAndCompare(pos, _chromosomeLength) ? 1 : 0;
        if (countRepeated == 2) {
            return true;
        }
        // check in \ direaction
        countRepeated += extractAndCompare(pos, _chromosomeLength + 1) ? 1 : 0;
        if (countRepeated == 2) {
            return true;
        }
        // check in / direction
        countRepeated += extractAndCompare(pos, -_chromosomeLength + 1) ? 1 : 0;
        if (countRepeated == 2) {
            return true;
        }
    }

    return false;
}
