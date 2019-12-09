package main

//思路：go中没有栈，用数组来模拟栈。利用ASCII码，如果遍历到左半括号，转换为右半括号压入栈，
//如果遍历到右半括号，若此时栈中元素为空，即栈顶指针为0，则说明找不到匹配的左半括号，返回false，
//若此时栈中元素不为空，且栈顶元素（top - 1）的值刚好等于右半括号的ASCII码，则说明找到了匹配的括号，
//弹出栈顶元素（top--）

func isValid(s string) bool {
	if s == "" {
		return true
	}

	size := len(s)
	stack := make([]byte, size)
	top := 0

	for i := 0; i < size; i++ {
		left := s[i]
		switch left {
		case '(' :
			stack[top] = left + 1 //利用ASCII码, '(' + 1 = ')'
			top++
		case '[', '{':
			stack[top] = left + 2 //利用ASCII码, '[' + 2 = ']'，'{' + 2 = '}'
			top++
		case ')', ']', '}':
			if top > 0 && stack[top - 1] == left {
				top--
			} else {
				return false
			}
		}
	}
	return top == 0
}
