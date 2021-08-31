#pragma once
#include <vector>
#include <memory>
#include "diceAnalyzer.h"
#include "constInfo.h"

class ICategory {
public:
    virtual ~ICategory() {}

    virtual int getScore(const DiceAnalyzer& da, const GameInfo& gi) = 0;
    virtual const char* getName() = 0;
};

class DiceCalculator {
public:
    DiceCalculator();
    ~DiceCalculator();

    std::size_t getHighestScoreCategories(const DiceAnalyzer& da, const GameInfo& gi, std::vector<std::unique_ptr<ScoreResult> >& out_result);

private:
    std::vector<ICategory*> categories;
};

class SingleCategory : public ICategory {
public:
    SingleCategory(const char* _name, int _dice);

    virtual int getScore(const DiceAnalyzer& da, const GameInfo& gi) final;
    virtual const char* getName() final;

private:
    std::string name;
    int dice;
};

class FullHouseCategory : public ICategory {
public:
    virtual int getScore(const DiceAnalyzer& da, const GameInfo& gi) final;
    virtual const char* getName() final;
};

class FiveOfAKindCategory : public ICategory {
public:
    virtual int getScore(const DiceAnalyzer& da, const GameInfo& gi) final;
    virtual const char* getName() final;
};

class StraightCategory : public ICategory {
public:
    virtual int getScore(const DiceAnalyzer& da, const GameInfo& gi) final;
    virtual const char* getName() final;

private:
    bool small = false;
};

class PhoenixCategory : public ICategory {
public:
    virtual int getScore(const DiceAnalyzer& da, const GameInfo& gi) final;
    virtual const char* getName() final;
};
