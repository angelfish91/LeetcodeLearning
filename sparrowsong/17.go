package leetcode

func helper(ch byte, ans []string) []string {

	res := make([]string, 0, len(ans)*3)
	aaa := []string{}

	switch ch {
	case '2':
		aaa = append(aaa, "a", "b", "c")
	case '3':
		aaa = append(aaa, "d", "e", "f")
	case '4':
		aaa = append(aaa, "g", "h", "i")
	case '5':
		aaa = append(aaa, "j", "k", "l")
	case '6':
		aaa = append(aaa, "m", "n", "o")
	case '7':
		aaa = append(aaa, "p", "q", "r", "s")
	case '8':
		aaa = append(aaa, "t", "u", "v")
	case '9':
		aaa = append(aaa, "w", "x", "y", "z")
	default:
		return ans
	}

	if len(ans) == 0 {
		for i := 0; i < len(aaa); i++ {
			res = append(res, aaa[i])
		}
		return res
	}

	for i := 0; i < len(aaa); i++ {
		for j := 0; j < len(ans); j++ {
			res = append(res, ans[j]+aaa[i])
		}
	}
	return res
}

func letterCombinations(digits string) []string {
	if len(digits) == 0 {
		return []string{}
	}
	ans := []string{}
	for _, ch := range []byte(digits) {
		ans = helper(ch, ans)
	}
	return ans
}
