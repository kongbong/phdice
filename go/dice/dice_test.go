package dice

import (
	"testing"

	"github.com/stretchr/testify/assert"
)

func TestOnes(t *testing.T) {
	game := NewGame(1, 8, 6)

	rst, err := game.GetHighestScoreCategories([]int{1, 1, 1, 1, 2, 3})
	assert.Nil(t, err, "error should be nil")
	assert.Equal(t, 1, len(rst), "categories size should be 1")
	assert.Equal(t, "Ones", rst[0].Name, "category name should be Ones")
	assert.Equal(t, 4, rst[0].Score, "category score should be 4")
}

func TestInvalidDice(t *testing.T) {
	game := NewGame(1, 8, 6)

	_, err := game.GetHighestScoreCategories([]int{1, 1, 1, 1, 2, 3, 1})
	assert.NotNil(t, err, "error should be not nil")

	_, err = game.GetHighestScoreCategories([]int{})
	assert.NotNil(t, err, "error should be not nil")

	_, err = game.GetHighestScoreCategories([]int{1, 2, 3})
	assert.NotNil(t, err, "error should be not nil")

	_, err = game.GetHighestScoreCategories([]int{1, 2, 3, 4, 5, 68})
	assert.NotNil(t, err, "error should be not nil")
}

func TestSigles(t *testing.T) {
	game := NewGame(1, 8, 6)

	rst, err := game.GetHighestScoreCategories([]int{2, 2, 2, 1, 3, 4})
	assert.Nil(t, err, "error should be nil")
	assert.Equal(t, 1, len(rst), "categories size should be 1")
	assert.Equal(t, "Twos", rst[0].Name, "category name should be Twos")
	assert.Equal(t, 6, rst[0].Score, "category score should be 6")

	rst, err = game.GetHighestScoreCategories([]int{3, 3, 3, 1, 2, 4})
	assert.Nil(t, err, "error should be nil")
	assert.Equal(t, 1, len(rst), "categories size should be 1")
	assert.Equal(t, "Threes", rst[0].Name, "category name should be Threes")
	assert.Equal(t, 9, rst[0].Score, "category score should be 9")

	rst, err = game.GetHighestScoreCategories([]int{4, 4, 4, 4, 1, 2})
	assert.Nil(t, err, "error should be nil")
	assert.Equal(t, 1, len(rst), "categories size should be 1")
	assert.Equal(t, "Fours", rst[0].Name, "category name should be Fours")
	assert.Equal(t, 16, rst[0].Score, "category score should be 16")

	rst, err = game.GetHighestScoreCategories([]int{5, 5, 5, 5, 1, 2})
	assert.Nil(t, err, "error should be nil")
	assert.Equal(t, 1, len(rst), "categories size should be 1")
	assert.Equal(t, "Fives", rst[0].Name, "category name should be Fives")
	assert.Equal(t, 20, rst[0].Score, "category score should be 20")

	rst, err = game.GetHighestScoreCategories([]int{6, 6, 6, 6, 1, 2})
	assert.Nil(t, err, "error should be nil")
	assert.Equal(t, 1, len(rst), "categories size should be 1")
	assert.Equal(t, "Sixes", rst[0].Name, "category name should be Sixes")
	assert.Equal(t, 24, rst[0].Score, "category score should be 24")

	rst, err = game.GetHighestScoreCategories([]int{7, 7, 7, 7, 1, 2})
	assert.Nil(t, err, "error should be nil")
	assert.Equal(t, 1, len(rst), "categories size should be 1")
	assert.Equal(t, "Sevens", rst[0].Name, "category name should be Sevens")
	assert.Equal(t, 28, rst[0].Score, "category score should be 28")

	rst, err = game.GetHighestScoreCategories([]int{8, 8, 8, 8, 1, 2})
	assert.Nil(t, err, "error should be nil")
	assert.Equal(t, 1, len(rst), "categories size should be 1")
	assert.Equal(t, "Eights", rst[0].Name, "category name should be Eights")
	assert.Equal(t, 32, rst[0].Score, "category score should be 32")
}

func TestFullhouse(t *testing.T) {
	game := NewGame(1, 8, 6)

	rst, err := game.GetHighestScoreCategories([]int{2, 2, 2, 3, 3, 4})
	assert.Nil(t, err, "error should be nil")
	assert.Equal(t, 1, len(rst), "categories size should be 1")
	assert.Equal(t, "Full House", rst[0].Name, "category name should be Full House")
	assert.Equal(t, 12, rst[0].Score, "category score should be 12")

	rst, err = game.GetHighestScoreCategories([]int{2, 2, 2, 3, 3, 3})
	assert.Nil(t, err, "error should be nil")
	assert.Equal(t, 1, len(rst), "categories size should be 1")
	assert.Equal(t, "Full House", rst[0].Name, "category name should be Full House")
	assert.Equal(t, 13, rst[0].Score, "category score should be 13")

	rst, err = game.GetHighestScoreCategories([]int{4, 3, 3, 4, 3, 4})
	assert.Nil(t, err, "error should be nil")
	assert.Equal(t, 1, len(rst), "categories size should be 1")
	assert.Equal(t, "Full House", rst[0].Name, "category name should be Full House")
	assert.Equal(t, 18, rst[0].Score, "category score should be 18")
}

func TestFiveOfAKind(t *testing.T) {
	game := NewGame(1, 8, 6)

	rst, err := game.GetHighestScoreCategories([]int{4, 4, 4, 4, 3, 4})
	assert.Nil(t, err, "error should be nil")
	assert.Equal(t, 2, len(rst), "categories size should be 1")
	assert.Equal(t, "Fours", rst[0].Name, "first category name should be Fours")
	assert.Equal(t, 20, rst[0].Score, "first category score should be 20")
	assert.Equal(t, "Five-of-a-Kind", rst[1].Name, "second category name should be Five-of-a-Kind")
	assert.Equal(t, 20, rst[1].Score, "category score should be 20")

	rst, err = game.GetHighestScoreCategories([]int{6, 6, 6, 6, 6, 1})
	assert.Nil(t, err, "error should be nil")
	assert.Equal(t, 2, len(rst), "categories size should be 1")
	assert.Equal(t, "Sixes", rst[0].Name, "first category name should be Sixes")
	assert.Equal(t, 30, rst[0].Score, "first category score should be 30")
	assert.Equal(t, "Five-of-a-Kind", rst[1].Name, "second category name should be Five-of-a-Kind")
	assert.Equal(t, 30, rst[1].Score, "second category score should be 30")

	rst, err = game.GetHighestScoreCategories([]int{6, 6, 6, 6, 6, 5})
	assert.Nil(t, err, "error should be nil")
	assert.Equal(t, 2, len(rst), "categories size should be 1")
	assert.Equal(t, "Sixes", rst[0].Name, "first category name should be Sixes")
	assert.Equal(t, 30, rst[0].Score, "first category score should be 30")
	assert.Equal(t, "Five-of-a-Kind", rst[1].Name, "second category name should be Five-of-a-Kind")
	assert.Equal(t, 30, rst[1].Score, "second category score should be 30")
}

func TestStraight(t *testing.T) {
	game := NewGame(1, 8, 6)

	rst, err := game.GetHighestScoreCategories([]int{8, 1, 2, 3, 4, 5})
	assert.Nil(t, err, "error should be nil")
	assert.Equal(t, 1, len(rst), "categories size should be 1")
	assert.Equal(t, "Small Straight", rst[0].Name, "category name should be Small Straight")
	assert.Equal(t, 30, rst[0].Score, "category score should be 30")

	rst, err = game.GetHighestScoreCategories([]int{8, 2, 1, 5, 4, 3})
	assert.Nil(t, err, "error should be nil")
	assert.Equal(t, 1, len(rst), "categories size should be 1")
	assert.Equal(t, "Small Straight", rst[0].Name, "category name should be Small Straight")
	assert.Equal(t, 30, rst[0].Score, "category score should be 30")

	rst, err = game.GetHighestScoreCategories([]int{1, 2, 3, 4, 5, 6})
	assert.Nil(t, err, "error should be nil")
	assert.Equal(t, 1, len(rst), "categories size should be 1")
	assert.Equal(t, "Straight", rst[0].Name, "category name should be Straight")
	assert.Equal(t, 40, rst[0].Score, "category score should be 40")
}

func TestPhoenix(t *testing.T) {
	game := NewGame(1, 8, 6)

	rst, err := game.GetHighestScoreCategories([]int{1, 1, 1, 1, 1, 1})
	assert.Nil(t, err, "error should be nil")
	assert.Equal(t, 1, len(rst), "categories size should be 1")
	assert.Equal(t, "Phoenix", rst[0].Name, "category name should be Phoenix")
	assert.Equal(t, 50, rst[0].Score, "category score should be 50")
}
