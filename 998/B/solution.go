package main

import (
	"fmt"
	"sort"
)

func PriOne(a interface{}) {
	switch a.(type) {
	case int, int8, int16, int32, int64:
		fmt.Printf("%d", a)
	case string:
		fmt.Printf("%s", a)
	case byte:
		fmt.Printf("%c", a)
	case []interface{}, []int64:
		fmt.Printf("%+v", a)
	}
}

func Pri(a ...interface{}) {
	for _, interf := range a {
		PriOne(interf)
	}
}

func ReadOne(a interface{}) {
	cnt, err := fmt.Scan(a)
	if err != nil {
		fmt.Printf("%s\n", err)
	}
	if cnt != 1 {
		fmt.Printf("cnt not right\n")
	}
}

func Read(a ...interface{}) {
	for _, interf := range a {
		ReadOne(interf)
	}
}

func ReadInt64List(a *[]int64, len int) {
	b := int64(0)
	for i := 0; i < len; i++ {
		Read(&b)
		*a = append(*a, b)
	}
}

func cal(a, b int64) int64 {
	ret := a / b
	if a%b != 0 {
		ret++
	}
	return ret
}

func main() {
	n, m := 0, int64(0)
	l := []int64{0}
	Read(&n, &m)
	ReadInt64List(&l, n)
	cnt := 0
	l = append(l, 1000000)
	for i := 1; i <= n; i++ {
		if l[i]&1 == 1 {
			cnt++
		} else {
			cnt--
		}
		if cnt == 0 {
			l[0]++
			l[l[0]] = l[i+1] - l[i]
			if l[l[0]] < 0 {
				l[l[0]] = -l[l[0]]
			}
		}
	}
	l = l[:l[0]+1]
	length := l[0]
	l = l[1:]
	sort.Slice(l, func(i, j int) bool {
		return l[i] < l[j]
	})
	ans := 0
	for i := int64(0); i < length; i++ {
		if l[i] <= m {
			ans++
			m -= l[i]
		}
	}
	Pri(ans)
}

