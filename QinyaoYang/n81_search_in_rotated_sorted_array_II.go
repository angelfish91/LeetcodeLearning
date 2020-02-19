package main

//Time:O(logn)，Space:O(1)
//与第33题思路一致，问题在于，存在重复数字可能会出现如 [1,0,1,1,1] 或者 [1,1,1,0,1]的情况
//此时 nums[low] == nums[mid]，无法确定到底是前面有序还是后面有序
//遇到这种情况时，就直接将 low + 1，丢掉一个重复数，再继续循环即可
func searchII(nums []int, target int) bool {
	length := len(nums)
	if length == 0 {
		return false
	}

	low, high := 0, length -1
	for low <= high {
		mid := low + ((high - low) >> 1)
		if nums[mid] == target {
			return true
		}
		if nums[mid] == nums[low] { //出现特殊情况时，直接将 low++
			low++
			continue
		}
		if nums[mid] >= nums[low] {
			if target < nums[mid] && target >= nums[low] {
				high = mid - 1
			} else {
				low = mid + 1
			}
		} else {
			if target > nums[mid] && target <= nums[high] {
				low = mid + 1
			} else {
				high = mid - 1
			}
		}
	}
	return false
}
