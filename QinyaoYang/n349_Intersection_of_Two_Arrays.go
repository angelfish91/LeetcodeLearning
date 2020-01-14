package main

//Time：O(m + n)，Space：O(m)
func intersection(nums1 []int, nums2 []int) []int {
	count := make(map[int]int)

	for _, val := range nums1 {
		if _, ok := count[val]; !ok {
			count[val] = 1
		}
	}

	var res []int
	for _, val := range nums2 {
		if v, ok := count[val]; ok && v != 0 {
			res = append(res, val)
			count[val] = 0
		}
	}
	return res
}
