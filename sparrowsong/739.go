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

// a better solution
func dailyTemperatures2(T []int) []int {
	ans := make([]int, len(T))
	for idx := len(T) - 1; idx >= 0; idx-- {
		if idx == len(T)-1 {
			continue
		}
		if T[idx] < T[idx+1] {
			ans[idx] = 1
		} else {
			x := idx + 1
			for x < len(T) {
				if T[idx] < T[x+ans[x]] {
					ans[idx] = x + ans[x] - idx
					break
				}
				if ans[x] == 0 {
					break
				}
				x += ans[x]
			}
		}
	}
	return ans
}
