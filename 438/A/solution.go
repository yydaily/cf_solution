package main

import (
	"fmt"
	"sort"
)

func ReadInt64() int64 { /*{{{*/
	var ret int64
	_, err := fmt.Scan(&ret)
	if err != nil {
		return 0
	}
	return ret
} /*}}}*/

type pair struct {
	ind  int64
	cost int64
}

func addEdge(a, b int64, m map[int64][]int64) {
	if m[a] == nil {
		m[a] = []int64{b}
	} else {
		m[a] = append(m[a], b)
	}
}

func main() {
	n, m := ReadInt64(), ReadInt64()
	costList := []pair{}
	value := []int64{}
	edge := map[int64][]int64{}

	for i := int64(0); i < n; i++ { /*{{{*/
		a := ReadInt64()
		value = append(value, a)
		costList = append(costList, pair{
			ind:  i,
			cost: a,
		})
	} /*}}}*/
	for i := int64(0); i < m; i++ {
		a, b := ReadInt64(), ReadInt64()
		a--
		b--
		addEdge(a, b, edge)
		addEdge(b, a, edge)
	}
	ans := int64(0)
	sort.Slice(costList, func(i, j int) bool {
		return costList[i].cost > costList[j].cost
	})
	for _, p := range costList {
		for _, to := range edge[p.ind] {
			ans += value[to]
		}
		value[p.ind] = 0
	}
	fmt.Printf("%d\n", ans)
}

