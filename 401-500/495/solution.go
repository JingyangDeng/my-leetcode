//一次遍历，维护中毒失效的时间
func findPoisonedDuration(timeSeries []int, duration int) int {
    time, ret := 0, -duration
    for _, t := range timeSeries {
        if t < time {
            ret += duration - time + t
        } else {
            ret += duration
        }
        time = t + duration
    }
    ret += duration
    return ret
}
