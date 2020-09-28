package main

import (
	"fmt"
	"sort"
)

func ReadInt64() int64 {
	var ret int64
	_, err := fmt.Scan(&ret)
	if err != nil {
		return 0
	}
	return ret
}

type pair struct {
	first  int64
	second int64
}

func main() {
	n, k, sum := int64(0), int64(0), int64(0)
	n, k = ReadInt64(), ReadInt64()
	a, b := make([]pair, n), make([]pair, k+1)

	for i := int64(0); i < n; i++ {
		a[i].first = ReadInt64()
		a[i].second = i + 1
	}
	sort.Slice(a, func(i, j int) bool { return a[i].first < a[j].first })
	for i := int64(0); i < k; i++ {
		sum += a[n-i-1].first
	}
	fmt.Printf("%d\n", sum)
	for i := int64(1); i <= k; i++ {
		b[i] = a[n-i]
	}
	sort.Slice(b, func(i, j int) bool { return b[i].second < b[j].second })
	for i := int64(1); i < k; i++ {
		fmt.Printf("%d ", b[i].second-b[i-1].second)
	}
	fmt.Printf("%d\n", n-b[k-1].second)
}

