package main

//写法一
func validateStackSequences(pushed []int, popped []int) bool {
	length := len(pushed)
	var stack []int
	popNum := 0
	for _, v := range pushed {
		stack = append(stack, v)
		for len(stack) != 0 && popNum < length && popped[popNum] == stack[len(stack) - 1] {
			popNum++
			stack = stack[: len(stack) - 1]
		}
	}
	return popNum == length
}

//写法二
func validateStackSequences1(pushed []int, popped []int) bool {
	length := len(pushed)
	stack := make([]int, length)
	top := -1

	for pushIdx, popIdx := 0, 0; pushIdx < length; pushIdx++ {
		if pushed[pushIdx] != popped[popIdx] { //如果压入元素不等于弹出元素，则执行入栈
			top++
			stack[top] = pushed[pushIdx]
		} else { //如果压入元素等于弹出元素，当前元素不入栈
			popIdx++ //popIdx指针后移，检查下一个弹出元素是否在栈顶
			for top >=0 && stack[top] == popped[popIdx] {
				top--
				popIdx++
			}
		}
	}
	return top == -1
}