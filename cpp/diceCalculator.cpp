#include "diceCalculator.h"
#include <iostream>

DiceCalculator::DiceCalculator() {
    categories.push_back(new SingleCategory{ "Ones", 1 });
    categories.push_back(new SingleCategory{ "Twos", 2 });
    categories.push_back(new SingleCategory{ "Threes", 3 });
    categories.push_back(new SingleCategory{ "Fours", 4 });
    categories.push_back(new SingleCategory{ "Fives", 5 });
    categories.push_back(new SingleCategory{ "Sixes", 6 });
    categories.push_back(new SingleCategory{ "Sevens", 7 });
    categories.push_back(new SingleCategory{ "Eights", 8 });
    categories.push_back(new FullHouseCategory{ });
    categories.push_back(new FiveOfAKindCategory{ });
    categories.push_back(new StraightCategory{ });
    categories.push_back(new PhoenixCategory{ });
}

DiceCalculator::~DiceCalculator() {
    for (auto cate : categories) {
        delete cate;
    }
    categories.clear();
}

std::size_t DiceCalculator::getHighestScoreCategories(const DiceAnalyzer& da, const GameInfo& gi, std::vector<std::unique_ptr<ScoreResult> >& out_result) {
    int maxScore = 0;
    for (auto cate : categories) {
        int score = cate->getScore(da, gi);
        if (score > maxScore) {
            maxScore = score;
            out_result.clear();
            out_result.push_back(std::unique_ptr<ScoreResult>{new ScoreResult{ cate->getName(), score }});
        } else if (score == maxScore) {
            out_result.push_back(std::unique_ptr<ScoreResult>{new ScoreResult{ cate->getName(), score }});
        }
    }
    return out_result.size();
}

SingleCategory::SingleCategory(const char* _name, int _dice)
: name(_name)
, dice(_dice) {

}

int SingleCategory::getScore(const DiceAnalyzer& da, const GameInfo& gi) {
    return da.getCnt(dice) * dice;
}

const char* SingleCategory::getName() {
    return name.c_str();
}

int FullHouseCategory::getScore(const DiceAnalyzer& da, const GameInfo& gi) {
    bool found = false;
	int majorNo = -1;
	int minorNo = -1;
	for (int i = gi.maxDice; i >= gi.minDice; i--) {
		if (da.getCnt(i) >= 3) {
			found = true;
			majorNo = i;
			break;
		}
	}
	if (!found) {
		return 0;
	}

	found = false;
	for (int i = gi.minDice; i <= gi.maxDice; i++) {
		if (i != majorNo && da.getCnt(i) >= 2) {
			found = true;
			minorNo = i;
			break;
		}
	}
    if (!found) {
        return 0;
    }
	return 3*majorNo + 2*minorNo;
}

const char* FullHouseCategory::getName() {
    return "Full House";
}

int FiveOfAKindCategory::getScore(const DiceAnalyzer& da, const GameInfo& gi) {
    for (int i = gi.maxDice; i >= gi.minDice; i--) {
		if (da.getCnt(i) >= 5) {
			return da.getCnt(i) * i;
		}
	}
	return 0;
}

const char* FiveOfAKindCategory::getName() {
    return "Five-of-a-Kind";
}

int StraightCategory::getScore(const DiceAnalyzer& da, const GameInfo& gi) {
    int cnt = da.getStraight();
	if (cnt == 5) {
		small = true;
		return 30;
	} else if (cnt == 6) {
		small = false;
		return 40;
	}
	return 0;
}

const char* StraightCategory::getName() {
    if (small) {
        return "Small Straight";
    }
    return "Straight";
}

int PhoenixCategory::getScore(const DiceAnalyzer& da, const GameInfo& gi) {
    for (int i = gi.maxDice; i >= gi.minDice; i--) {
		if (da.getCnt(i) == 6) {
			return 50;
		}
	}
	return 0;
}

const char* PhoenixCategory::getName() {
    return "Phoenix";
}