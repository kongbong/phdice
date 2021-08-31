#pragma once
#include <string>

const int MinDice = 1;
const int MaxDice = 8;
const int DiceCnt = 6;

struct ScoreResult {
    std::string Name;
    int Score;
};

struct GameInfo {
    int minDice;
    int maxDice;
    std::size_t diceCnt;
};

//#define DEBUG 1