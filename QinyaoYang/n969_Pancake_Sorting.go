package main

import (
	"math"
)

//将区间分为【无序区，有序区】,从后往前遍历，每次都从无序区中找出最大元素的下标，翻转0-最大元素下标之间的数字，这样就将
//最大元素放到了数组开头，然后再翻转整个无序区，就把最大元素换到了数组最后
func pancakeSort(A []int) []int {
	length := len(A)
	var res []int
	for i := length - 1; i > 0; i-- {
		maxidx := maxIdx(&A, i) //找出无序区中的最大元素
		if maxidx > 0 {
			res = append(res, maxidx + 1) //最大元素下标+1加入结果集
			listReverse(&A, 0, maxidx) //第一次翻转
		}
		listReverse(&A, 0, i) //第二次翻转
		res = append(res, i + 1) //无序区结尾下标+1加入结果集
	}
	return res
}

func maxIdx(num *[]int, end int) int {
	maxNum := math.MinInt64
	max := 0
	for i := 0; i <= end; i++ {
		if (*num)[i] > maxNum {
			maxNum = (*num)[i]
			max = i
		}
	}
	return max
}

func listReverse(num *[]int, begin, end int) {
	for begin < end {
		(*num)[begin], (*num)[end] = (*num)[end], (*num)[begin]
		begin++
		end--
	}
	return
}