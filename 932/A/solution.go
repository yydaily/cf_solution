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
	case byte:
		fmt.Printf("%c", a)
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
	a := ""
	Read(&a)
	Pri(a)
	for i := len(a)-1; i >=0; i-- {
		Pri(a[i])
	}
}

