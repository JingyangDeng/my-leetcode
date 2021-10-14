func countAndSay(n int) string {
    str := "1"
    for k := 1; k < n; k++ {
        var tmp string
        var cnt, mem int
        for i , c := range str {
            if i == 0 {
                mem = int(c)
                cnt = 1
            } else if int(c) == mem {
                cnt++
            } else {
                tmp += (strconv.Itoa(cnt) + strconv.Itoa(mem - 48))
                mem = int(c)
                cnt = 1
            }
        }
        tmp += (strconv.Itoa(cnt) + strconv.Itoa(mem - 48))
        str = tmp
    }
    return str
}
