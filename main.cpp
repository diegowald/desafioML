#include <iostream>
#include <vector>
#include <string>

#include "dnaanalyzer.h"

//using namespace std;

bool isEqual(const std::string &chain, std::size_t startPos)
{
    return chain[startPos] == chain[startPos + 1] &&
           chain[startPos] == chain[startPos + 2] &&
           chain[startPos] == chain[startPos + 3];
}


unsigned int countHorizontallyMutants(const std::vector<std::string> &dna)
{
    int count = 0;
    for (auto chain: dna) {
        for (std::size_t startPos = 0; startPos < chain.length() - 4; ++startPos) {
            bool result = isEqual(chain, startPos);
            count += result ? 1 : 0;
            if (result) {
                std::cout << chain << std::endl;
            }
        }
    }
    return count;
}


unsigned int countVerticallyMutants(const std::vector<std::string> &dna)
{
    std::vector<std::string> transposedVector(dna.size());
    for (std::size_t i = 0; i < dna.size(); ++i) {
        std::string chain = dna[i];
        for (std::size_t j = 0; j < chain.length(); ++j) {
            transposedVector[j] += chain[j];
        }
    }

    return countHorizontallyMutants(transposedVector);
}

unsigned int countDiagonallyMutants(const std::vector<std::string> &dna)
{
    std::vector<std::string> chains;
    // create the \ chains
    for (std::size_t i = 0; i < dna.size() - 4; ++i) {
        for (std::size_t j = 0; j < dna.size() - 4; ++j) {
            std::string chain {""};
            for (std::size_t k = 0; k < 4; ++k) {
                chain += dna[i + k][j + k];
            }
            chains.push_back(chain);
        }
    }
    // create de / chains
    for (std::size_t i = 3; i < dna.size(); ++i) {
        for (std::size_t j = 0; j < dna.size() - 4; ++j) {
            std::string chain {""};
            for (std::size_t k = 0; k < 4; ++k) {
                chain += dna[i - k][j + k];
            }
            chains.push_back(chain);
        }
    }
    return countHorizontallyMutants(chains);
}

bool isMutant(const std::vector<std::string> &dna)
{
    unsigned int minRepetitions = 2;
    unsigned int repeatedCharLength = 4;
    for (auto chain: dna) {
        std::cout << chain << std::endl;
    }
    std::cout << "========================" << std::endl;

    unsigned int result = countHorizontallyMutants(dna);
    if (result > 1) {
        return true;
    }

    result += countVerticallyMutants(dna);
    if (result > 1) {
        return true;
    }

    result += countDiagonallyMutants(dna);
    if (result > 1) {
        return true;
    }

    return false;
}

int main()
{
    std::vector<std::string> dna {"ATGCGA","CAGTGC","TTATGT","AGAAGG","CCCCTA","TCACTG"};

    bool result = isMutant(dna);
    std::cout << "isMutant: " << (result ? "true" : "false") << std::endl;

    DNAAnalyzer dnaAnalyzer;
    dnaAnalyzer.chain(dna);
    dnaAnalyzer.repetitionLength(4);
    result = dnaAnalyzer.isMutant();
    std::cout << "isMutant: " << (result ? "true" : "false") << std::endl;
    return 0;
}
