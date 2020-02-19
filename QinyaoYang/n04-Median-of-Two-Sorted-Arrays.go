package main

import "LeetcodeLearning/utils"

// 方法一
func findMedianSortedArrays1(nums1 []int, nums2 []int) float64 {
	total := len(nums1) + len(nums2)
	if (total & 1) == 1 {
		//如果是奇数，则中位数等于有序数组中第 total/2 + 1 小的数
		return findKthSmallestInSortedArrays(nums1, nums2, total/2+1)
	} else {
		//如果是偶数，中位数等于有序数组中第 total/2 + 1 和第 total/2 两个数的和的平均值
		c1 := findKthSmallestInSortedArrays(nums1, nums2, total/2+1)
		c2 := findKthSmallestInSortedArrays(nums1, nums2, total/2)
		return (c1 + c2) * 0.5
	}
}

func findKthSmallestInSortedArrays(nums1, nums2 []int, k int) float64 {
	l1, l2 := len(nums1), len(nums2) //表示当前数组还剩下的数的个数
	delt1, delt2 := 0, 0 //当前数组的起点，下标小于 delt1 和 delt2 的数已经被排除

	for {
		//循环退出的条件：
		if l1 == 0 { // 说明nums1中的所有数都被排除了
			//此时 nums2 中前delt2-1个数已经被排除，要找有序数组中第k小的数，就在nums2中取第k个
			return float64(nums2[delt2+k-1])
		}
		if l2 == 0 {//同上
			return float64(nums1[delt1+k-1])
		}
		if k == 1 {// 说明此时要找的是有序数组中最小的那个数
			return float64(utils.Min(nums1[delt1], nums2[delt2]))
		}

		i := utils.Min(k/2, l1) // 从 nums1 中取k/2个数，和当前 nums1 的长度进行比较，取小的那个值
		j := utils.Min(k-i, l2) // 从 nums2 中取剩下的数
		a, b := nums1[delt1+i-1], nums2[delt2+j-1]

		if i+j == k && a == b { //此时从两个数中取出的数刚好相等，并且这两个数是第k-1和第k个数，则直接返回
			return float64(a)
		}

		//运行到这里还没有返回，说明取数的范围不对，要调整
		// 复杂度之所以是log级别，是因为在下面两步中，每次都会抛弃掉不符合条件的 k/2 个数，而 logk < log(m + n)，所以符合要求
		if a <= b { // 说明从 nums1 中取数取小了
			delt1 += i // 说明 nums1 中的前 i 个数都不符合要求，丢弃（通过设置偏移量 delt1 来模拟设置数组的边界
			l1 -= i // nums1 现在的范围是[delt1:]，修改其长度
			k -= i // 因为从 nums1 中丢掉了 i 个数，所以相应的 k 也要变换
		}

		//同上
		if a >= b {
			delt2 += j
			l2 -= j
			k -= j
		}
	}
}