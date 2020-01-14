package main

import "sort"

//方法一：排序以后使用双指针，Time：O(nlogn)，Space：O(n)
func isAnagram(s string, t string) bool {
	if len(s) != len(t) {
		return false
	}

	w1 := []byte(s)
	w2 := []byte(t)

	sort.Slice(w1, func(i, j int) bool {
		return w1[i] < w1[j]
	})
	sort.Slice(w2, func(i, j int) bool {
		return w2[i] < w2[j]
	})

	i,j := 0,0
	for i < len(s) && j < len(t) {
		if w1[i] != w2[j] {
			return false
		}
		i++
		j++
	}
	return true
}

//方法二
func isAnagram1(s string, t string) bool {
	if len(s) != len(t) {
		return false
	}

	temp := make([]int, 26)
	for _, v := range s {
		temp[v - 'a']++
	}

	for _, v := range t {
		if val := temp[v - 'a']; val <= 0 {
			return false
		} else {
			temp[v - 'a']--
		}
	}
	return true
}
