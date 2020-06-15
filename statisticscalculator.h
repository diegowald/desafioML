#ifndef STATISTICSCALCULATOR_H
#define STATISTICSCALCULATOR_H

#include "DTO.h"

class StatisticsCalculator
{
public:
    StatisticsCalculator(unsigned long long mutantCount, unsigned long long humanCount);

    unsigned long long mutantCount() const;
    unsigned long long humanCount() const;

    double ratio() const;

private:
    unsigned long long _mutantCount;
    unsigned long long _humanCount;
};

#endif // STATISTICSCALCULATOR_H
