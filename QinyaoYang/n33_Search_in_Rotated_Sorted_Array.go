package main

//Time:O(logn)，Space:O(1)
func searchInRotatedSortedArray(nums []int, target int) int {
	size := len(nums)
	if size == 0 {
		return -1
	}

	low, high := 0, size-1
	for low <= high {
		mid := low + ((high - low) >> 1)
		if nums[mid] == target {
			return mid
		}
		if nums[mid] >= nums[low] { //说明当前mid在前半部分递增区间中
			if target < nums[mid] && target >= nums[low] { //说明target也在前半递增区间中
				high = mid - 1 //则在前半递增区间中执行二分法，target < nums[mid]，则要减小high
			} else { //说明target不在前半递增区间中
				low = mid + 1 //则将low下标前移，使得下次迭代mid能落到后半递增区间中
			}
		} else {
			if target > nums[mid] && target <= nums[high] {
				low = mid + 1
			} else {
				high = mid - 1
			}
		}
	}
	return -1
}
