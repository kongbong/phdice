#include "diceAnalyzer.h"
#include <algorithm>

void DiceAnalyzer::init(const std::vector<int>& dices) {
    sortedDices = dices;
    std::sort(sortedDices.begin(), sortedDices.end());

    for (int dice : dices) {
        diceCntMap[dice]++;
    }
}

int DiceAnalyzer::getCnt(int dice) const {
    auto itr = diceCntMap.find(dice);
    if (itr != diceCntMap.cend()) {
        return itr->second;
    }
    return 0;
}

int DiceAnalyzer::getStraight() const {
    int last = sortedDices[0];
	int cnt = 1;
	int maxCnt = 0;
	for (size_t i = 1; i < sortedDices.size(); i++) {
		if (sortedDices[i] == last+1) {
			// straight
			cnt++;
			last++;
		} else {
			if (cnt > maxCnt) {
				maxCnt = cnt;
			}
			cnt = 1;
			last = sortedDices[i];
		}
	}
	if (cnt > maxCnt) {
		maxCnt = cnt;
	}
	return maxCnt;
}