package leetcode

func mySqrt(x int) int {
	if x == 1 || x == 0 {
		return x
	}
	st, ed := 0, x
	middle := (st + ed) / 2
	for middle*middle != x && middle != st && middle != ed {
		println(middle)
		if middle*middle < x {
			st = middle
		} else {
			ed = middle
		}
		middle = (st + ed) / 2
	}
	return middle
}
