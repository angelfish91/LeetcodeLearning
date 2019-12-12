package leetcode

func validateStackSequences(pushed []int, popped []int) bool {
	if len(pushed) == 0 {
		return true
	}
	helper := []int{pushed[0]}
	p0 := -1
	p1 := 0
	for {
		p0++
		helper = append(helper, pushed[p0])
		if helper[len(helper)-1] == popped[p1] {
			helper = helper[:len(helper)-1]
			break
		}
	}
	for {
		p1++
		if p1 >= len(popped) {
			break
		}
		if popped[p1] == helper[len(helper)-1] {
			helper = helper[:len(helper)-1]
			continue
		}
		flag := false
		for {
			p0++
			if p0 >= len(pushed) {
				break
			}
			helper = append(helper, pushed[p0])
			if popped[p1] == helper[len(helper)-1] {
				helper = helper[:len(helper)-1]
				flag = true
				break
			}
		}
		if !flag {
			return false
		}
	}
	return true
}
