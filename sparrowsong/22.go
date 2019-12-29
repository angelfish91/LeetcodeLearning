package leetcode

var result []string

func generateParenthesis(n int) []string {
	result = nil
	var a, b []string
	for i := 0; i < n; i++ {
		a = append(a, "(")
		b = append(b, ")")
	}
	gen(a, b, "")

	return result
}

func gen(a, b []string, s string) {
	if len(a) == 0 && len(b) == 0 {
		result = append(result, s)
	}
	if len(a) > 0 {
		tmp := s
		tmp += a[0]
		gen(a[1:], b, tmp)
	}
	if len(b) > len(a) {
		tmp := s
		tmp += b[0]
		gen(a, b[1:], tmp)
	}
}
