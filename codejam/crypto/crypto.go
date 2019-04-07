package main

import (
	"bufio"
	"fmt"
	"math/big"
	"os"
	"sort"
	"strconv"
	"strings"
)

type ByBigInt []*big.Int

func (a ByBigInt) Len() int           { return len(a) }
func (a ByBigInt) Swap(i, j int)      { a[i], a[j] = a[j], a[i] }
func (a ByBigInt) Less(i, j int) bool { return a[i].Cmp(a[j]) < 0 }

func processString(input string) []*big.Int {
	ret := make([]*big.Int, 0)
	tmp := strings.Split(input, " ")
	for _, v := range tmp {
		t := new(big.Int)
		t, _ = t.SetString(v, 10)
		ret = append(ret, t)
	}
	return ret
}

func compute(condition, num []*big.Int) string {
	l := int(condition[1].Int64())
	keys := make([]*big.Int, l+1)
	ret := []string{}
	stack := []int{0}
	solveIdx := -1
	for i := 1; i < len(num); i++ {
		// fmt.Println(i)
		if solveIdx == -1 && num[i-1].Cmp(num[i]) == 0 {
			stack = append(stack, i)
		} else if solveIdx == -1 && num[i-1].Cmp(num[i]) != 0 {
			solveIdx = i
			k := new(big.Int)
			k = k.GCD(nil, nil, num[i-1], num[i])
			keys[i] = k
			nextK := num[i]
			nextK = nextK.Div(nextK, k)
			keys[i+1] = nextK
			ls := len(stack)
			// fmt.Println(i, stack, keys)
			for j := i; ls > 0; {
				p := stack[ls-1]
				tmp := num[j-1]
				// fmt.Println("-", tmp, k)
				tmp = tmp.Div(tmp, k)
				keys[p] = tmp
				stack = stack[:ls-1]
				k = tmp
				ls = len(stack)
				j--
			}
			// fmt.Println(i, stack, keys)
		} else {
			//next key value
			gcd := keys[i]
			k := num[i]
			k = k.Div(k, gcd)
			keys[i+1] = k
			// fmt.Println(i, keys, gcd)
		}
	}
	// fmt.Println(keys)
	hash := getHash(keys)
	for _, v := range keys {
		ret = append(ret, hash[v.String()])
	}
	return strings.Join(ret, "")
}

func getHash(n []*big.Int) map[string]string {
	ret := map[string]string{}
	l := []*big.Int{}
	for _, v := range n {
		k := v.String()
		if _, ok := ret[k]; !ok {
			ret[k] = " "
			l = append(l, v)
		}
	}
	sort.Sort(ByBigInt(l))
	for i, v := range l {
		k := v.String()
		ret[k] = string('A' + rune(i))
	}
	return ret
}

func main() {
	ret := []string{}

	reader := bufio.NewReader(os.Stdin)
	text, err := reader.ReadString('\n')
	if err != nil {
		fmt.Println(err)
	}
	text = strings.TrimSuffix(text, "\n")
	t, err := strconv.Atoi(text)
	if err != nil {
		fmt.Println(err)
	}
	for i := 0; i < t; i++ {
		line1, _ := reader.ReadString('\n')
		line1 = strings.TrimSuffix(line1, "\n")
		line2, _ := reader.ReadString('\n')
		line2 = strings.TrimSuffix(line2, "\n")

		l1 := processString(line1)
		l2 := processString(line2)
		// fmt.Println(l1, l2)
		ret = append(ret, compute(l1, l2))
	}
	for i := 0; i < len(ret); i++ {
		fmt.Printf("Case #%d: %s\n", i+1, ret[i])
	}
}
