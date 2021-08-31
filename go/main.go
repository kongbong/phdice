package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
	"phdice/dice"
	"strconv"
	"strings"
)

const (
	MinDice = 1
	MaxDice = 8
	DiceCnt = 6
)

func main() {
	game := dice.NewGame(MinDice, MaxDice, DiceCnt)

	for {
		fmt.Println("Start new round, Input 6 dices:")
		dices, err := readDices(os.Stdin)
		if err != nil {
			fmt.Println(err)
			return
		}
		rst, err := game.GetHighestScoreCategories(dices)
		if err != nil {
			fmt.Println(err)
			return
		}

		fmt.Println("Highest Categories:")
		for i := 0; i < len(rst); i++ {
			fmt.Println(rst[i].Name, "Score:", rst[i].Score)
		}

		fmt.Println("Want more play? [y/n]")
		var word string
		fmt.Scanln(&word)
		word = strings.ToUpper(word)
		if word != "Y" && word != "YES" {
			break
		}
	}
}

// read numbers from input reader and returns a list of numbers
func readDices(input io.Reader) ([]int, error) {
	scanner := bufio.NewScanner(input)
	scanner.Split(bufio.ScanWords)

	rst := []int{}
	for scanner.Scan() {
		no, err := strconv.Atoi(scanner.Text())
		if err != nil {
			return nil, fmt.Errorf("failed to read number from input err:%w", err)
		}
		if no < MinDice || no > MaxDice {
			return nil, fmt.Errorf("dice number should be %d~%d, but current dice number is %d", MinDice, MaxDice, no)
		}
		rst = append(rst, no)
		if len(rst) == DiceCnt {
			break
		}
	}
	return rst, nil
}
