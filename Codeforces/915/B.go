package main

import (
	. "fmt"
	"io"
	"os"
)

func abs(a int) int {
	if a < 0 {
		a = -a
	}
	return a
}
func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}
func solve(in io.Reader, out io.Writer) {
	var n, p, l, r int
	Fscan(in, &n, &p, &l, &r)
	// Fprint(out, n, p, l, r)
	p1 := p
	//先r然后l
	ans2 := 0
	p = p1
	ans2 += abs(p - r)
	p = r
	if p != n {
		ans2++
	}
	ans2 += abs(p - l)
	p = l
	if p != 1 {
		ans2++
	}
	//先l然后r
	ans1 := 0
	p = p1
	ans1 += abs(p - l)
	p = l
	if p != 1 {
		ans1++
	}
	ans1 += abs(p - r)
	p = r
	if p != n {
		ans1++
	}
	//
	ans := min(ans1, ans2)
	if l == 1 {
		p = p1
		x := 0
		x += abs(p - r)
		p = r
		if p != n {
			x++
		}
		ans = min(ans, x)
	}
	if r == n {
		p = p1
		x := 0
		x += abs(p - l)
		p = l
		if p != 1 {
			x++
		}
		ans = min(ans, x)
	}
	if l == 1 && r == n {
		ans = min(ans, 0)
	}
	Fprint(out, ans)
}

func main() {
	in, out := os.Stdin, os.Stdout
	solve(in, out)
}
