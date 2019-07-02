package main

import "fmt"

type node struct{
	val string
	children map[string]*node
}

func newNode( v string) *node {
	return &node{v, make(map[string]*node, 0)}
}

func (n *node) insert( word string){
	var cur = n;
	for i:=0; i < len(word);i++{
		var let = string(word[i])
		if _,ok := cur.children[let];!ok{
			cur.children[let] = newNode(let)
		}
		cur = cur.children[let]
	}
	cur.children["*"] = newNode("*")
}

func longestWord(words []string) string {
	var root = newNode("")

	for i:= 0; i<len(words);i++{
		root.insert(words[i])
	}

	// search the trie to find the ans
	var ans = ""

	var dfs func(*node, string)

	dfs = func(n *node, path string){
		for k,v:=range n.children{
			var np = path + k
			if _,ok:= v.children["*"];ok{
				if len(np)>len(ans){
					ans = np
				}else if len(np) == len(ans) && np < ans{
					ans = np
				}
				if len(v.children) >1{
					dfs(v,np)
				}
			}
		}
	}
	dfs(root,"")
	// fmt.Println(ans)
	return ans
}

func main(){
	var x = longestWord([]string{"ogz","eyj","e","ey","hmn","v","hm","ogznkb","ogzn","hmnm","eyjuo","vuq","ogznk","og","eyjuoi","d"})
	fmt.Println(x)
}