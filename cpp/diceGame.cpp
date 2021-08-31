#include "diceGame.h"
#include "diceAnalyzer.h"
#include "diceCalculator.h"

#include <iostream>

DiceGame::DiceGame(int _minDice, int _maxDice, std::size_t _diceCnt)
: gameInfo{_minDice, _maxDice, _diceCnt}
, calculator{ new DiceCalculator{ }}
{

}

DiceGame::~DiceGame() {
    delete calculator;
    calculator = nullptr;
}

std::size_t DiceGame::getHighestScoreCategories(const std::vector<int>& dices, std::vector<std::unique_ptr<ScoreResult> >& out_result)
{
    if (dices.size() != gameInfo.diceCnt) {
        std::cout << "Dice count should be " << gameInfo.diceCnt << " but count is " << dices.size() << std::endl;
        return 0;
    }

    for (auto dice : dices) {
        if (dice < gameInfo.minDice || dice > gameInfo.maxDice) {
            std::cout << "Dice should be between " << gameInfo.minDice << "~" << gameInfo.maxDice << " but dice is " << dice << std::endl;
            return 0;
        }
    }

    DiceAnalyzer diceAnalyzer{};
    diceAnalyzer.init(dices);

    return calculator->getHighestScoreCategories(diceAnalyzer, gameInfo, out_result);
}
