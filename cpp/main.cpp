#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <limits>
#include "constInfo.h"
#include "diceGame.h"

bool readDices(std::vector<int>& dices);
void toUpper(std::string& str);
void flushStream(std::istream& stream);

#ifdef DEBUG
    void runTestCases();
#endif

int main() {
#ifdef DEBUG
    runTestCases();
    return 0;
#endif

    std::vector<int> dices;
    std::string line;
    std::vector<std::unique_ptr<ScoreResult> > result;

    DiceGame game{ MinDice, MaxDice, DiceCnt };

    while (true) {
        std::cout << "Start new round - input 6 dices:" << std::endl;
        dices.clear();
        if (!readDices(dices)) {
            std::cout << "Failed to read dices!" << std::endl;
            return 0;
        }

        int n = game.getHighestScoreCategories(dices, result);
        for (int i = 0; i < n; i++) {
            std::cout << result[i]->Name << " Score:" << result[i]->Score << std::endl;
        }
        result.clear();

        std::cout << "Play more? [y/n]" << std::endl;
        flushStream(std::cin);
        std::getline(std::cin, line);
        toUpper(line);
        if (line != "Y" && line != "YES") {
            return 0;
        }
    }
}

bool readDices(std::vector<int>& dices) {
    int cnt = 0;
    int dice = 0;
    std::string tmp;
    while (std::cin >> dice) {
        dices.push_back(dice);
        cnt++;
        if (cnt == DiceCnt) {
            return true;
        }
    }
    return false;
}

void toUpper(std::string& str) {
    for (auto & c: str) c = toupper(c);
}

void flushStream(std::istream& stream) {
    stream.ignore(256,'\n');
}
