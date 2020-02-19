package main

func searchInsert(nums []int, target int) int {
	if len(nums) == 0 {
		return -1
	}
	low, high := 0, len(nums)-1
	for low <= high { //注意等号不要漏
		mid := low + (high - low>>1)
		if nums[mid] < target {
			low = mid + 1
		} else if nums[mid] > target {
			high = mid - 1
		} else {
			return mid
		}
	}
	return low //若数组中不存在待插入的数，最终的插入位置是low
}
