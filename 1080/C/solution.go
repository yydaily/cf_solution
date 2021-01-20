package main

import (
	"fmt"
)

func PriOne(a interface{}) {
	switch a.(type) {
	case int, int8, int16, int32, int64:
		fmt.Printf("%d", a)
	case string:
		fmt.Printf("%s", a)
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

func cal(a, b int64) int64 {
	ret := a / b
	if a%b != 0 {
		ret++
	}
	return ret
}

func main() {
	a, b := int64(0), int64(0)
	Read(&a, &b)
	Pri(cal(a<<1, b) + cal(a*5, b) + cal(a<<3, b))
}


