package main

//二分法
func mySqrt(x int) int {
	if x < 2 {
		return x
	}

	low, high := 0, x / 2
	for low <= high {
		mid := low + ((high - low) >> 1)
		if mid * mid < x {
			low = mid + 1
		} else if mid * mid > x {
			high = mid - 1
		} else {
			return mid
		}
	}
	return high
}

//牛顿迭代
func mySqrt1(x int) int {
	a := x
	for a * a > x {
		a = (a + x / a) / 2
	}
	return a
}