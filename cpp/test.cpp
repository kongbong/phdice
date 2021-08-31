#include "constInfo.h"
#include "diceGame.h"

#include <iostream>
#include <vector>

#ifdef DEBUG
void runTestCases() {
    DiceGame game{ MinDice, MaxDice, DiceCnt };
    std::vector<std::unique_ptr<ScoreResult> > result;

    // Ones Test
    int n = game.getHighestScoreCategories({1, 1, 1, 1, 2, 3}, result);
    if (result.size() != 1 || n != 1) {
        std::cout << "result size should be one. size:" << n << std::endl;
        return;
    }
    if (result[0]->Name != "Ones") {
        std::cout << "category name should be Ones. name:" << result[0]->Name << std::endl;
        return;
    }
    if (result[0]->Score != 4) {
        std::cout << "category score should be 4. score:" << result[0]->Score << std::endl;
        return;
    }

    // Invalid Values
    result.clear();
    n = game.getHighestScoreCategories({1, 1, 1, 1, 2, 3, 1}, result);
    if (n != 0) {
        std::cout << "result size should be zero. size:" << n << std::endl;
        return;
    }

    result.clear();
    n = game.getHighestScoreCategories({}, result);
    if (n != 0) {
        std::cout << "result size should be zero. size:" << n << std::endl;
        return;
    }
    
    result.clear();
    n = game.getHighestScoreCategories({1, 2, 3}, result);
    if (n != 0) {
        std::cout << "result size should be zero. size:" << n << std::endl;
        return;
    }

    result.clear();
    n = game.getHighestScoreCategories({1, 2, 3, 4, 5, 68}, result);
    if (n != 0) {
        std::cout << "result size should be zero. size:" << n << std::endl;
        return;
    }

    // Twos
    result.clear();
    n = game.getHighestScoreCategories({2, 2, 2, 1, 3, 4}, result);
	if (result.size() != 1 || n != 1) {
        std::cout << "result size should be one. size:" << n << std::endl;
        return;
    }
    if (result[0]->Name != "Twos") {
        std::cout << "category name should be Twos. name:" << result[0]->Name << std::endl;
        return;
    }
    if (result[0]->Score != 6) {
        std::cout << "category score should be 6. score:" << result[0]->Score << std::endl;
        return;
    }

    // Threes
    result.clear();
    n = game.getHighestScoreCategories({3, 3, 3, 1, 2, 4}, result);
	if (result.size() != 1 || n != 1) {
        std::cout << "result size should be one. size:" << n << std::endl;
        return;
    }
    if (result[0]->Name != "Threes") {
        std::cout << "category name should be Threes. name:" << result[0]->Name << std::endl;
        return;
    }
    if (result[0]->Score != 9) {
        std::cout << "category score should be 9. score:" << result[0]->Score << std::endl;
        return;
    }

    // Fours
    result.clear();
    n = game.getHighestScoreCategories({4, 4, 4, 4, 1, 2}, result);
	if (result.size() != 1 || n != 1) {
        std::cout << "result size should be one. size:" << n << std::endl;
        return;
    }
    if (result[0]->Name != "Fours") {
        std::cout << "category name should be Fours. name:" << result[0]->Name << std::endl;
        return;
    }
    if (result[0]->Score != 16) {
        std::cout << "category score should be 16. score:" << result[0]->Score << std::endl;
        return;
    }

    // Fives
    result.clear();
    n = game.getHighestScoreCategories({5, 5, 5, 5, 1, 2}, result);
	if (result.size() != 1 || n != 1) {
        std::cout << "result size should be one. size:" << n << std::endl;
        return;
    }
    if (result[0]->Name != "Fives") {
        std::cout << "category name should be Fours. name:" << result[0]->Name << std::endl;
        return;
    }
    if (result[0]->Score != 20) {
        std::cout << "category score should be 20. score:" << result[0]->Score << std::endl;
        return;
    }

    // Sixes
    result.clear();
    n = game.getHighestScoreCategories({6, 6, 6, 6, 1, 2}, result);
	if (result.size() != 1 || n != 1) {
        std::cout << "result size should be one. size:" << n << std::endl;
        return;
    }
    if (result[0]->Name != "Sixes") {
        std::cout << "category name should be Sixes. name:" << result[0]->Name << std::endl;
        return;
    }
    if (result[0]->Score != 24) {
        std::cout << "category score should be 24. score:" << result[0]->Score << std::endl;
        return;
    }

    // Sevens
    result.clear();
    n = game.getHighestScoreCategories({7, 7, 7, 7, 1, 2}, result);
	if (result.size() != 1 || n != 1) {
        std::cout << "result size should be one. size:" << n << std::endl;
        return;
    }
    if (result[0]->Name != "Sevens") {
        std::cout << "category name should be Sevens. name:" << result[0]->Name << std::endl;
        return;
    }
    if (result[0]->Score != 28) {
        std::cout << "category score should be 28. score:" << result[0]->Score << std::endl;
        return;
    }

    // Eights
    result.clear();
    n = game.getHighestScoreCategories({8, 8, 8, 8, 1, 2}, result);
	if (result.size() != 1 || n != 1) {
        std::cout << "result size should be one. size:" << n << std::endl;
        return;
    }
    if (result[0]->Name != "Eights") {
        std::cout << "category name should be Eights. name:" << result[0]->Name << std::endl;
        return;
    }
    if (result[0]->Score != 32) {
        std::cout << "category score should be 32. score:" << result[0]->Score << std::endl;
        return;
    }

    // Full Houes
    result.clear();
    n = game.getHighestScoreCategories({2, 2, 2, 3, 3, 4}, result);
	if (result.size() != 1 || n != 1) {
        std::cout << "result size should be one. size:" << n << std::endl;
        return;
    }
    if (result[0]->Name != "Full House") {
        std::cout << "category name should be Full House. name:" << result[0]->Name << std::endl;
        return;
    }
    if (result[0]->Score != 12) {
        std::cout << "category score should be 12. score:" << result[0]->Score << std::endl;
        return;
    }

    result.clear();
    n = game.getHighestScoreCategories({2, 2, 2, 3, 3, 3}, result);
	if (result.size() != 1 || n != 1) {
        std::cout << "result size should be one. size:" << n << std::endl;
        return;
    }
    if (result[0]->Name != "Full House") {
        std::cout << "category name should be Full House. name:" << result[0]->Name << std::endl;
        return;
    }
    if (result[0]->Score != 13) {
        std::cout << "category score should be 13. score:" << result[0]->Score << std::endl;
        return;
    }

    result.clear();
    n = game.getHighestScoreCategories({4, 3, 3, 4, 3, 4}, result);
	if (result.size() != 1 || n != 1) {
        std::cout << "result size should be one. size:" << n << std::endl;
        return;
    }
    if (result[0]->Name != "Full House") {
        std::cout << "category name should be Full House. name:" << result[0]->Name << std::endl;
        return;
    }
    if (result[0]->Score != 18) {
        std::cout << "category score should be 18. score:" << result[0]->Score << std::endl;
        return;
    }

    // Five-of-a-Kind
    result.clear();
    n = game.getHighestScoreCategories({4, 4, 4, 4, 3, 4}, result);
	if (result.size() != 2 || n != 2) {
        std::cout << "result size should be 2. size:" << n << " line:" << __LINE__ << std::endl;
        return;
    }
    if (result[0]->Name != "Fours") {
        std::cout << "first category name should be Fours. name:" << result[0]->Name << std::endl;
        return;
    }
    if (result[0]->Score != 20) {
        std::cout << "first category score should be 20. score:" << result[0]->Score << std::endl;
        return;
    }
    if (result[1]->Name != "Five-of-a-Kind") {
        std::cout << "second category name should be Five-of-a-Kind. name:" << result[1]->Name << std::endl;
        return;
    }
    if (result[1]->Score != 20) {
        std::cout << "second category score should be 20. score:" << result[1]->Score << std::endl;
        return;
    }

    result.clear();
    n = game.getHighestScoreCategories({6, 6, 6, 6, 6, 1}, result);
	if (result.size() != 2 || n != 2) {
        std::cout << "result size should be 2. size:" << n << " line:" << __LINE__ <<  std::endl;
        return;
    }
    if (result[0]->Name != "Sixes") {
        std::cout << "first category name should be Sixes. name:" << result[0]->Name << std::endl;
        return;
    }
    if (result[0]->Score != 30) {
        std::cout << "first category score should be 30. score:" << result[0]->Score << std::endl;
        return;
    }
    if (result[1]->Name != "Five-of-a-Kind") {
        std::cout << "second category name should be Five-of-a-Kind. name:" << result[1]->Name << std::endl;
        return;
    }
    if (result[1]->Score != 30) {
        std::cout << "second category score should be 30. score:" << result[1]->Score << std::endl;
        return;
    }

    // Straight
    result.clear();
    n = game.getHighestScoreCategories({8, 1, 2, 3, 4, 5}, result);
	if (result.size() != 1 || n != 1) {
        std::cout << "result size should be one. size:" << n << std::endl;
        return;
    }
    if (result[0]->Name != "Small Straight") {
        std::cout << "category name should be Small Straight. name:" << result[0]->Name << std::endl;
        return;
    }
    if (result[0]->Score != 30) {
        std::cout << "category score should be 30. score:" << result[0]->Score << std::endl;
        return;
    }

    result.clear();
    n = game.getHighestScoreCategories({8, 2, 1, 5, 4, 3}, result);
	if (result.size() != 1 || n != 1) {
        std::cout << "result size should be one. size:" << n << std::endl;
        return;
    }
    if (result[0]->Name != "Small Straight") {
        std::cout << "category name should be Small Straight. name:" << result[0]->Name << std::endl;
        return;
    }
    if (result[0]->Score != 30) {
        std::cout << "category score should be 30. score:" << result[0]->Score << std::endl;
        return;
    }

    result.clear();
    n = game.getHighestScoreCategories({1, 2, 3, 4, 5, 6}, result);
	if (result.size() != 1 || n != 1) {
        std::cout << "result size should be one. size:" << n << std::endl;
        return;
    }
    if (result[0]->Name != "Straight") {
        std::cout << "category name should be Straight. name:" << result[0]->Name << std::endl;
        return;
    }
    if (result[0]->Score != 40) {
        std::cout << "category score should be 40. score:" << result[0]->Score << std::endl;
        return;
    }

    result.clear();
    n = game.getHighestScoreCategories({1, 1, 1, 1, 1, 1}, result);
	if (result.size() != 1 || n != 1) {
        std::cout << "result size should be one. size:" << n << " line:" << __LINE__ << std::endl;
        return;
    }
    if (result[0]->Name != "Phoenix") {
        std::cout << "category name should be Phoenix. name:" << result[0]->Name << std::endl;
        return;
    }
    if (result[0]->Score != 50) {
        std::cout << "category score should be 50. score:" << result[0]->Score << std::endl;
        return;
    }

    std::cout << "TEST OK" << std::endl;
}
#endif