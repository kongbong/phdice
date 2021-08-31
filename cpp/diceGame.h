#pragma once
#include <vector>
#include <memory>
#include "constInfo.h"

class DiceCalculator;

class DiceGame {
public:
    DiceGame(int _minDice, int _maxDice, std::size_t _diceCnt);
    ~DiceGame();

    std::size_t getHighestScoreCategories(const std::vector<int>& dices, std::vector<std::unique_ptr<ScoreResult> >& out_result);

private:
    GameInfo gameInfo;
    DiceCalculator* calculator;
};