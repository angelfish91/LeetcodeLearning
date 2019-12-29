package leetcode

func addDigits(num int) int {
	if num/10 == 0 {
		return num % 10
	}
	ans := 0
	for num > 0 {
		ans += num % 10
		num /= 10
	}
	return addDigits(ans)
}
