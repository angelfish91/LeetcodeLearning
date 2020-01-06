package main

func relativeSortArray(arr1 []int, arr2 []int) []int {
	count := make([]int, 1001)
	res := make([]int, 0, 1001)

	for _, v := range arr1 {
		count[v]++
	}

	for _, v := range arr2 {
		for count[v] > 0 {
			res = append(res, v)
			count[v]--
		}
	}

	for i, v := range count {
		for v > 0 {
			res = append(res, i)
			v--
		}
	}
	return res
}

//func main() {
//	arr1 := []int{2,3,1,3,2,4,6,7,9,2,19}
//	arr2 := []int{2,1,4,3,9,6}
//	relativeSortArray(arr1, arr2)
//}