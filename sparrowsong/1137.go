package leetcode

var m = map[int]int{
	0: 0,
	1: 1,
	2: 1,
}

func tribonacci(n int) int {
	if v, ok := m[n]; ok {
		return v
	}
	m[n] = tribonacci(n-1) + tribonacci(n-2) + tribonacci(n-3)
	return m[n]
}
