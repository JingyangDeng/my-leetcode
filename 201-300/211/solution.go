//前缀树
type WordDictionary struct {
    next []*WordDictionary
    end bool
}

func Constructor() WordDictionary {
    var dic WordDictionary
    dic.next = make([]*WordDictionary, 26)
    dic.end = false
    return dic
}

func (this *WordDictionary) AddWord(word string)  {
    root := this
    for _, c := range word {
        child := root.next[int(c)-'a']
        if child == nil {
            tree := Constructor()
            root.next[int(c)-'a'] = &tree
        }
        root = root.next[int(c)-'a']
    }
    root.end = true
}

func Dfs(root *WordDictionary, word string, p int) bool {
    if root == nil {
        return false
    }
    if p == len(word) {
        return root.end
    }
    if word[p] != '.' {
        return Dfs(root.next[int(word[p])-'a'], word, p + 1)
    }
    for i := 0; i < 26; i++ {
        if(Dfs(root.next[i], word, p + 1)) {
            return true
        }
    }
    return false
}

func (this *WordDictionary) Search(word string) bool {
    return Dfs(this, word, 0)
}


/**
 * Your WordDictionary object will be instantiated and called as such:
 * obj := Constructor();
 * obj.AddWord(word);
 * param_2 := obj.Search(word);
 */
