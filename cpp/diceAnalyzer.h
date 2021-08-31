#pragma once
#include <vector>
#include <map>

class DiceAnalyzer {
public:
    void init(const std::vector<int>& dices);
    int getCnt(int dice) const;
    int getStraight() const;

private:
    std::map<int, int> diceCntMap;
    std::vector<int> sortedDices;
};