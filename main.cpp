#include <iostream>
#include <vector>
#include <string>

#include "dnaanalyzer.h"

//using namespace std;

int main()
{
    std::vector<std::string> dna {"ATGCGA","CAGTGC","TTATGT","AGAAGG","CCCCTA","TCACTG"};

    DNAAnalyzer dnaAnalyzer;
    dnaAnalyzer.chain(dna);
    dnaAnalyzer.repetitionLength(4);
    bool result = dnaAnalyzer.isMutant();
    std::cout << "isMutant: " << (result ? "true" : "false") << std::endl;
    return 0;
}
