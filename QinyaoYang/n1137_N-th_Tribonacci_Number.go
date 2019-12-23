package main

func tribonacci(n int) int {
	a := 0
	b, c := 1, 1

	if n == 0 {
		return 0
	} else if n == 1 || n == 2 {
		return 1
	}

	for i := 3; i <= n; i++ {
		a, b, c = b, c, a + b + c
	}
	return c
}

//练习闭包
func helper() func() int {
	a, count := 0, 0
	b, c := 1, 1
	return func() int {
		switch count {
		case 0 :
			count++
			return 0
		case 1, 2 :
			count++
			return 1
		default:
			count++
			a, b, c = b, c, a + b + c
			return c
		}
	}
}

func tribonacci1(n int) int {
	tribFunc := helper()
	for i := 0; i <= n - 1; i++ {
		tribFunc()
	}
	return tribFunc()
}
