package dice

import (
	"fmt"
)

type Result struct {
	Name  string
	Score int
}

type Game struct {
	gameInfo
	calculator *ScoreCalculator
}

func NewGame(minDice, maxDice, diceCnt int) *Game {
	return &Game{
		gameInfo: gameInfo{
			minDice, maxDice, diceCnt,
		},
		calculator: NewScoreCalculator(),
	}
}

type gameInfo struct {
	minDice int
	maxDice int
	diceCnt int
}

func (g *Game) GetHighestScoreCategories(dices []int) ([]Result, error) {
	if len(dices) != g.diceCnt {
		return nil, fmt.Errorf("dice cannot be more %d count", g.diceCnt)
	}
	for i := 0; i < len(dices); i++ {
		if dices[i] < g.minDice || dices[i] > g.maxDice {
			return nil, fmt.Errorf("dice number should be %d~%d, but current dice number is %d", g.minDice, g.maxDice, dices[i])
		}
	}

	return g.calculator.getHighestScoreCategories(NewAnalyzer(dices), &g.gameInfo), nil
}
