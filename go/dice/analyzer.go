package dice

import (
	"sort"
)

type Analyzer struct {
	dices  []int
	counts map[int]int
}

func NewAnalyzer(dices []int) *Analyzer {
	cntMap := make(map[int]int)
	for i := 0; i < len(dices); i++ {
		cntMap[dices[i]]++
	}
	sort.Ints(dices)

	return &Analyzer{
		dices,
		cntMap,
	}
}

func (da *Analyzer) GetCnt(dice int) int {
	return da.counts[dice]
}

func (da *Analyzer) GetStraightCnt() int {

	last := da.dices[0]
	cnt := 1
	maxCnt := 0
	for i := 1; i < len(da.dices); i++ {
		if da.dices[i] == last+1 {
			// straight
			cnt++
			last++
		} else {
			if cnt > maxCnt {
				maxCnt = cnt
			}
			cnt = 1
			last = da.dices[i]
		}
	}
	if cnt > maxCnt {
		maxCnt = cnt
	}
	return maxCnt
}
