package main

import (
	. "fmt"
	"io"
	"os"
)

func Min(a, b int) int {
	if a < b {
		return a
	}
	return b
}
func solve(in io.Reader, out io.Writer) {
	var n, m int
	Fscan(in, &n, &m)
	a := make([]int, n+1)
	for i := 1; i <= n; i++ {
		Fscan(in, &a[i])
	}
	ans := int(1e9)
	for i := 1; i <= n; i++ {
		if m%a[i] == 0 {
			ans = Min(ans, m/a[i])
		}
	}
	Fprint(out, ans)
}
func main() {
	in, out := os.Stdin, os.Stdout
	solve(in, out)
}
