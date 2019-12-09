package leetcode

func isValid(s string) bool {
	helper := map[byte]int{
		'(': -1, '{': -2, '[': -3, ')': 1, '}': 2, ']': 3,
	}
	stack := []int{}
	for _, b := range []byte(s) {
		i := helper[b]
		if i < 0 {
			stack = append(stack, i)
		} else {
			if len(stack) > 0 && -stack[len(stack)-1] == i {
				stack = stack[:len(stack)-1]
			} else {
				return false
			}
		}
	}
	if len(stack) == 0 {
		return true
	}
	return false
}
