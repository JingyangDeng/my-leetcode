//简单逻辑
func fizzBuzz(n int) []string {
    ret := make([]string, n)
    for i:=0; i<n; i++ {
        ok := false
        if (i+1) % 3 == 0 {
            ok = true
            ret[i] = "Fizz"
        }
        if (i+1) % 5 == 0 {
            ok = true
            ret[i] += "Buzz"
        }
        if !ok {
            ret[i] = strconv.Itoa(i+1)
        }
    }
    return ret
}
