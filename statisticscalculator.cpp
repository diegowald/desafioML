#include "statisticscalculator.h"

StatisticsCalculator::StatisticsCalculator(unsigned long long mutantCount, unsigned long long humanCount) :
    _mutantCount(mutantCount), _humanCount(humanCount)
{
}


double StatisticsCalculator::ratio() const
{
    return (1. * _mutantCount) / (_humanCount == 0 ? 1 : _humanCount);
}

unsigned long long StatisticsCalculator::mutantCount() const
{
    return _mutantCount;
}

unsigned long long StatisticsCalculator::humanCount() const
{
    return _humanCount;
}
