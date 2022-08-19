//一次遍历
func busyStudent(startTime []int, endTime []int, queryTime int) int {
    cnt := 0
    for i:=0; i<len(startTime); i++ {
        if startTime[i]<= queryTime && queryTime <= endTime[i] {
            cnt++
        }
    }
    return cnt
}

