package main
import (
	"fmt"
)
func cinOne(a interface{}) {
	cnt, err := fmt.Scan(a)
	if err != nil {
		fmt.Printf("%s\n", err)
	}
	if cnt != 1 {
		fmt.Printf("cnt not right\n")
	}
}
func cin(a ...interface{}) {
	for _, interf := range a {
		cinOne(interf)
	}
}
func priOne(a interface{}) {
	switch a.(type) {
	case int, int8, int16, int32, int64:
		fmt.Printf("%d", a)
	case string:
		fmt.Printf("%s", a)
	}
}
func pri(a ...interface{}) {
	for _, interf := range a {
		priOne(interf)
	}
}
func main() {
	var n, a, b int64
	ans := 0
	cin(&n)
	for i := int64(0); i < n; i++ {
		cin(&a, &b)
		if b-a >= 2 {
			ans++
		}
	}
	pri(ans)
}

