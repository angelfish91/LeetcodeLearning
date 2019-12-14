package main

import (
	"strings"
)

//- 把路径按 "/" 进行分割，得到的结果有以下几种：
//  - "." ：当前路径，无需执行任何操作；
//  - "" ：空字符串，无需执行任何操作；
//  - ".." ：如果此时栈不为空，则执行pop操作；
//  - "路径" ：执行压栈操作；
//- 最后将结果使用"/"连接输出。

func simplifyPath(path string) string {
	var stack []string
	temp := strings.Split(path, "/")
	for _, v := range temp {
		switch v {
		case ".", "": //不执行任何操作
		case "..":
			if len(stack) != 0 {
				stack = stack[:len(stack) - 1]
			}
		default :
			stack = append(stack, v)
		}
	}
	return "/" + strings.Join(stack, "/")
}
