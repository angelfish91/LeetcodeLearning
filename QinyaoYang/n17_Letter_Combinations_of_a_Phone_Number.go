package main

//递归求解：Time：O(4^n)，Space：O(n)
var mapping = map[byte]string{
	0: "abc",
	1: "def",
	2: "ghi",
	3: "jkl",
	4: "mno",
	5: "pqrs",
	6: "tuv",
	7: "wxyz",
}

func letterCombinations(digits string) []string {
	if digits == "" {
		return nil
	}

	var result []string
	recursion(digits, 0, "", &result)
	return result

}

func recursion(digits string, idx int, str string, result *[]string) {
	if idx == len(digits) {
		*result = append(*result, str)
		return
	}

	chars := mapping[digits[idx]-'2']
	for i := 0; i < len(chars); i++ {
		nxtStr := str + string(chars[i])
		recursion(digits, idx+1, nxtStr, result)
	}
}

//迭代求解：
func letterCombinations1(digits string) []string {
	if digits == "" {
		return nil
	}
	res := []string{""}

	for i := 0; i < len(digits); i++ {
		chars := mapping[digits[i]-'2']
		var temp []string
		for j := 0; j < len(res); j++ {
			for k := 0; k < len(chars); k++ {
				temp = append(temp, res[j]+string(chars[k]))
			}
		}
		res = temp
	}

	return res
}

//func main() {
//	res := letterCombinations1("23")
//	fmt.Println(res)
//}
