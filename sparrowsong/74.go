package main

import (
//	"fmt"
)

func searchMatrix(matrix [][]int, target int) bool {
	if len(matrix) == 0 || len(matrix[0]) == 0 {
		return false
	}
	m := len(matrix)
	n := len(matrix[0])

	st_m, st_n := 0, 0
	st := matrix[st_m][st_n]
	ed_m, ed_n := m-1, n-1
	ed := matrix[ed_m][ed_n]

	delta := ed_m*m + ed_n - st_m*m - st_n
	md_m := (st_m*m+st_n+delta/2)/n - 1
	md_n := (st_m*m + st_n + delta/2) % n

	println(md_m, md_n)
	md := matrix[md_m][md_n]

	for md != target && md != st && md != ed {
		if md > target {
			ed_m = md_m
			ed_n = md_n
			ed = md
		} else {
			st_m = md_m
			st_n = md_n
			st = md
		}
		delta = ed_m*m + ed_n - st_m*m - st_n
		md_m = (st_m*m+st_n+delta/2)/n - 1
		md_n = (st_m*m + st_n + delta/2) % n
		md = matrix[md_m][md_n]
	}
	if md != target {
		return false
	}
	return true
}

func main() {
	println(searchMatrix([][]int{{1}, {3}, {5}}, 3))
	println(searchMatrix([][]int{{1, 3, 5}}, 3))
}
