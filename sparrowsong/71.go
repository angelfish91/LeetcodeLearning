package leetcode

func simplifyPath(path string) string {
	ans := []string{}
	paths := strings.Split(path, "/")
	for _, path := range paths {
		if path == "." || len(path) == 0 {
			continue
		}
		if path == ".." {
			if len(ans) >= 1 {
				ans = ans[:len(ans)-1]
			}
			continue
		}
		ans = append(ans, path)
	}
	return "/" + strings.Join(ans, "/")
}
