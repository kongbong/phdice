package dice

type Category interface {
	getScore(da *Analyzer, gi *gameInfo) int
	getName() string
}

type ScoreCalculator struct {
	categories []Category
}

func NewScoreCalculator() *ScoreCalculator {
	return &ScoreCalculator{
		categories: []Category{
			SingleCategory{1, "Ones"},
			SingleCategory{2, "Twos"},
			SingleCategory{3, "Threes"},
			SingleCategory{4, "Fours"},
			SingleCategory{5, "Fives"},
			SingleCategory{6, "Sixes"},
			SingleCategory{7, "Sevens"},
			SingleCategory{8, "Eights"},
			FullHouseCategory{},
			FiveOfAKindCategory{},
			&StraightCategory{},
			PhoenixCategory{},
		},
	}
}

func (dc ScoreCalculator) getHighestScoreCategories(da *Analyzer, gi *gameInfo) []Result {
	maxScore := 0
	var rst []Result
	for _, cate := range dc.categories {
		score := cate.getScore(da, gi)
		if score <= 0 {
			continue
		}
		if score > maxScore {
			maxScore = score
			rst = []Result{{cate.getName(), score}}
		} else if score == maxScore {
			rst = append(rst, Result{cate.getName(), score})
		}
	}

	return rst
}

type SingleCategory struct {
	number int
	name   string
}

func (c SingleCategory) getScore(da *Analyzer, gi *gameInfo) int {
	return da.GetCnt(c.number) * c.number
}

func (c SingleCategory) getName() string {
	return c.name
}

type FullHouseCategory struct {
}

func (FullHouseCategory) getScore(da *Analyzer, gi *gameInfo) int {
	found := false
	majorNo := -1
	minorNo := -1
	for i := gi.maxDice; i >= gi.minDice; i-- {
		if da.GetCnt(i) >= 3 {
			found = true
			majorNo = i
			break
		}
	}
	if !found {
		return 0
	}

	found = false
	for i := gi.minDice; i <= gi.maxDice; i++ {
		if i != majorNo && da.GetCnt(i) >= 2 {
			found = true
			minorNo = i
			break
		}
	}
	if !found {
		return 0
	}
	return 3*majorNo + 2*minorNo
}

func (FullHouseCategory) getName() string {
	return "Full House"
}

type FiveOfAKindCategory struct {
}

func (FiveOfAKindCategory) getScore(da *Analyzer, gi *gameInfo) int {
	for i := gi.maxDice; i >= gi.minDice; i-- {
		if da.GetCnt(i) >= 5 {
			return da.GetCnt(i) * i
		}
	}
	return 0
}

func (FiveOfAKindCategory) getName() string {
	return "Five-of-a-Kind"
}

type StraightCategory struct {
	small bool
}

func (s *StraightCategory) getScore(da *Analyzer, gi *gameInfo) int {
	cnt := da.GetStraightCnt()
	if cnt == 5 {
		s.small = true
		return 30
	} else if cnt == 6 {
		s.small = false
		return 40
	}
	return 0
}

func (s *StraightCategory) getName() string {
	if s.small {
		return "Small Straight"
	}
	return "Straight"
}

type PhoenixCategory struct {
}

func (PhoenixCategory) getScore(da *Analyzer, gi *gameInfo) int {
	for i := gi.maxDice; i >= gi.minDice; i-- {
		if da.GetCnt(i) == 6 {
			return 50
		}
	}
	return 0
}

func (PhoenixCategory) getName() string {
	return "Phoenix"
}
