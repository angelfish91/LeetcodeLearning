package leetcode

func permuteHelper(nums []int, ans [][]int) [][]int {
	if len(ans) == 0 {
		for _, num := range nums {
			ans = append(ans, []int{num})
		}
		return ans
	}

	res := [][]int{}
	for _, num := range nums {
		for _, v := range ans {
			flag := 0
			for _, vv := range v {
				if num == vv {
					flag = 1
					break
				}
			}
			if flag == 1 {
				continue
			}
			u := make([]int, len(v))
			copy(u, v)
			u = append(u, num)
			res = append(res, u)
		}
	}
	return res
}

func permute(nums []int) [][]int {
	ans := [][]int{}
	for i := 0; i < len(nums); i++ {
		ans = permuteHelper(nums, ans)
	}
	return ans
}
