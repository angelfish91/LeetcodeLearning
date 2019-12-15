package main

import (
	"fmt"
	"strings"
)
//方法一：暴力法：Time：O(n^2), Space：O(n)
func reverseParentheses(s string) string {
	if s == "" {
		return ""
	}

	size := len(s)
	stack := make([]string, 0, size)
	for i := 0; i < size; i++ {
		switch s[i] { //遍历字符串
		case '(': //如果遇到左半括号，将""压入栈顶
			stack = append(stack, "")
		case ')': //如果遇到右半括号，将栈顶字符串弹出，反转该部分字符串，再将结果加入到新的栈顶中
			top := stack[len(stack)-1]
			stack = stack[:len(stack)-1]
			if len(stack) == 0 { //如果此时栈为空，说明所有字符串均已完成反转，为了统一返回出口，将最终结果再压入栈中
				//注意此时不能再用stack[len(stack) - 1]来取栈顶元素，因此时len(stack) = 0,
				//stack[0]和stack[len(stack) - 1]都会使得下标越界
				stack = append(stack, reverseStrings(top))
				break
			}
			stack[len(stack)-1] = stack[len(stack)-1] + reverseStrings(top)
		default: //如果是非括号字符，则将结果拼接到栈顶字符串后
			//判断len(stack) == 0 是为了防止在栈为空时，使用下标操作导致越界,如："a(bcdefghijkl(mno)p)q"插入第一个a时
			if len(stack) == 0 {
				stack = append(stack, string(s[i]))
			} else {
				stack[len(stack)-1] += string(s[i])
			}
		}
	}
	return stack[len(stack)-1]
}

func reverseStrings(s string) string {
	size := len(s)
	res := make([]byte, 0, size)
	for i := size - 1; i >= 0; i-- {
		res = append(res, s[i])
	}
	return string(res)
}

//Time：O(n), Space：O(n)
func reverseParentheses1(s string) string {
	size := len(s)
	stack := make([]int, 0, size)
	pair := make([]int, size)
	for i := 0; i < size; i++ {
		switch s[i] {
		case '(':
			stack = append(stack, i)
		case ')':
			j := stack[len(stack) - 1]
			stack = stack[:len(stack) - 1]
			pair[i] = j
			pair[j] = i
		}
	}
	var sb strings.Builder
	for i, d := 0, 1; i < size; i+=d {
		if s[i] == '(' || s[i] == ')' {
			i = pair[i]
			d = -d
		} else {
			sb.WriteByte(s[i])
		}
	}
	return sb.String()
}

func main() {
	str1 := "(abcd)"
	str2 := "(u(love)i)"
	str3 := "(ed(et(oc))el)"
	str4 := "a(bcdefghijkl(mno)p)q"
	fmt.Println(reverseParentheses(str1))
	fmt.Println(reverseParentheses(str2))
	fmt.Println(reverseParentheses(str3))
	fmt.Println(reverseParentheses(str4))
}
