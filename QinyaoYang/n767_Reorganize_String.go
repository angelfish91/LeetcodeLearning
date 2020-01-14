package main

import "fmt"

func reorganizeString(S string) string {
	length := len(S)
	if length == 0 {
		return ""
	}

	temp := make([]byte, 26)
	var max uint8 = 0
	for _, v := range S {
		temp[v - 'a']++
		if temp[v - 'a'] > max {
			max = temp[v - 'a']
		}
	}

	//如果任意字符出现的次数超过了字符长度的一半，则无法满足题意，返回空字符串
	//注意这里一定要用 length + 1，因为整除是向下取整，不多加1的话会得到错误的结果，比如当字符串只有1个字符时
	if max > uint8((length + 1) / 2) {
		return ""
	}

	res := make([]byte, length)
	var even, odd  = 0, 1
	for i := range temp {
		for ;temp[i] > 0 && temp[i] < uint8(length / 2 + 1) && odd < length; {
			res[odd] = byte(i + 'a')
			temp[i]--
			odd += 2
		}

		for temp[i] > 0 {
			res[even] = byte(i + 'a')
			temp[i]--
			even += 2
		}
	}
	return string(res)
}

func main() {
	res := reorganizeString("abbabbaaab")
	fmt.Println(res)
}