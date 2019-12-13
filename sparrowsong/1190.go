package leetcode

func reverseParentheses(s string) string {
	res := ""
	splitBrS, splitBrE := findBr(s)
	for i := 0; i < len(splitBrS); i++ {
		if i == 0 {
			res += s[:splitBrS[0]]
		} else {
			res += s[splitBrE[i-1]+1 : splitBrS[i]]
		}
		res += reverseParenthesesHelper(s[splitBrS[i]+1 : splitBrE[i]])
		if i == len(splitBrS)-1 {
			res += s[splitBrE[i]+1:]
		}
	}
	if len(splitBrS) == 0 {
		return s
	}
	return res
}

func reverseParenthesesHelper(s string) string {
	splitBrS, splitBrE := findBr(s)
	if len(splitBrS) == 0 {
		return reverse(s)
	}
	res := []string{reverse(s[splitBrE[len(splitBrE)-1]+1:])}
	for i := len(splitBrS) - 1; i >= 0; i-- {
		res = append(res, reverse(reverseParenthesesHelper(s[splitBrS[i]+1:splitBrE[i]])))
		if i > 0 {
			res = append(res, reverse(s[splitBrE[i-1]+1:splitBrS[i]]))
		}
	}
	res = append(res, reverse(s[:splitBrS[0]]))
	return strings.Join(res, "")
}

func reverse(str string) string {
	var result []byte
	tmp := []byte(str)
	length := len(str)
	for i := 0; i < length; i++ {
		result = append(result, tmp[length-i-1])
	}
	return string(result)
}

func findBr(s string) ([]int, []int) {
	splitBrS := []int{}
	splitBrE := []int{}
	splitVec := []int{}
	for idx, ch := range []byte(s) {
		if ch == '(' {
			splitVec = append(splitVec, 1)
			if len(splitVec) == 1 {
				splitBrS = append(splitBrS, idx)
			}
		}
		if ch == ')' {
			if splitVec[len(splitVec)-1] == 1 {
				splitVec = splitVec[:len(splitVec)-1]
				if len(splitVec) == 0 {
					splitBrE = append(splitBrE, idx)
				}
			} else {
				splitVec = append(splitVec, -1)
			}
		}
	}
	return splitBrS, splitBrE
}
