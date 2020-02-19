package main

//Time：O(log(n))，Space：O(1)
//二分法的特点：如果查找的元素不在数组中，则返回的下标是该元素应该插入的位置的下标
//如果 目标值 < 中间值，则修正右边界，目标值 == 中间值，直接返回，目标值 > 中间值，修正左边界
//要找元素最后一次出现的位置，只需要在目标值等于中间值时，让其继续往右查找，也就是修正左边界
func searchRange(nums []int, target int) []int {
	size := len(nums)
	if size == 0 {
		return []int{-1, -1}
	}

	end := findLastIndex(&nums, target) //结束下标可以直接求得
	begin := findLastIndex(&nums, target-1) + 1 //起始下标用比target小1的数去求，求出来的结果加1即可

	if begin >= 0 && begin <= end && end < size { //注意这里还要验证两个下标的范围是否合法
		return []int{begin, end}
	}

	return []int{-1, -1}
}

//用于查找指定元素的最后一个下标
func findLastIndex(nums *[]int, target int) int {
	size := len(*nums)
	low, high := 0, size-1

	for low <= high {
		mid := low + (high - low>>1)
		//注意判断的条件是：如果mid对应的值大于target，high = mid - 1, 否则 low = mid + 1，顺序不能写反，等号是取在小于target那边
		if (*nums)[mid] > target {
			high = mid - 1
		} else {
			low = mid + 1
		}
	}
	return high //注意返回的下标是high
}
