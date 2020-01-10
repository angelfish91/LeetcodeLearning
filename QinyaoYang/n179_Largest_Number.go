package main

import (
	"fmt"
	"strconv"
)

func largestNumber(nums []int) string {
	length := len(nums)
	if length == 0 {
		return ""
	}

	temp := intToString(&nums)
	quickSortForLargestNum(&temp, 0, length - 1)
	var res string
	for _, v := range temp {
		if v == "0" && res == "0" { //注意这里不能用strings.Join来合并，对于[0,0]这种，返回值是0
			continue
		}
		res += v
	}
	return res
}

func intToString(nums *[]int) []string {
	res := make([]string, 0, len(*nums))
	for _, v := range *nums {
		res = append(res, strconv.Itoa(v))
	}
	return res
}

func quickSortForLargestNum(nums *[]string, start, end int) {
	if start < end {
		k := partitionFunc(nums, start, end)
		quickSortForLargestNum(nums, start, k - 1)
		quickSortForLargestNum(nums, k + 1, end)
	}
}

func partitionFunc(nums *[]string, start, end int) int {
	pivot := (*nums)[end]
	i := start
	for j := start; j < end; j++ {
		jpivot := (*nums)[j] + pivot
		pivotj := pivot + (*nums)[j]
		//pivot返回的位置是元素最终正确的位置，这个时候对于任意元素，应该满足pivot+元素的值大于元素+pivot的值
		//所以对于元素+pivot更大的情况，应该将元素放到pivot的后面
		if jpivot > pivotj {
			(*nums)[i], (*nums)[j] = (*nums)[j], (*nums)[i]
			i++
		}
	}
	(*nums)[i], (*nums)[end] = (*nums)[end],(*nums)[i]
	fmt.Println(*nums)
	return i
}

//func main() {
//	temp := []int{3,30,34,5,9}
//	res := largestNumber(temp)
//	fmt.Println(res)
//}