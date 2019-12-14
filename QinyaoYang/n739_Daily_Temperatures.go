package main

//Time：O(n), Space：O(n)
func dailyTemperatures(T []int) []int {
	length := len(T)
	var stack []int
	res := make([]int, length)

	for i := length - 1; i >= 0; i-- {
		for len(stack) != 0 && T[i] >= T[stack[len(stack) - 1]] { //注意等号不能漏
			stack = stack[: len(stack) - 1]
		}
		if len(stack) == 0 {
			res[i] = 0
		} else {
			res[i] = stack[len(stack) - 1] - i
		}
		stack = append(stack, i)
	}
	return res
}

//func main() {
//	res1 := dailyTemperatures([]int{73, 74, 75, 71, 69, 72, 76, 73})
//	res2 := dailyTemperatures([]int{89,62,70,58,47,47,46,76,100,70})
//	fmt.Println(res1)
//	fmt.Println(res2)
//}
