package leetcode

func dailyTemperatures(T []int) []int {
	res := make([]int, len(T))
	helper := []int{}
	for idx := len(T) - 1; idx >= 0; idx-- {
		res[idx] = 0
		for i := len(helper) - 1; i >= 0; i-- {
			if helper[i] > T[idx] {
				res[idx] = len(helper) - i
				break
			}
		}
		helper = append(helper, T[idx])
	}
	return res
}
