//mark!
//按照结束时间非降排序，依次考察课程c：
//若新的总完成时间 <= c的结束时间，加入课程
//否则，将之前最花时间的课程与c的花费时间比较（使用堆维护，按花费时间排序）
//若c的花费时间更小，将c加入，将此课程删除（课表依然可行，总时间减少，课程数不变）
import "container/heap"

type mostTimeHeap [][]int
func (h mostTimeHeap) Len()int {
	return len(h)
}
func (h mostTimeHeap) Less(i, j int) bool {
	return h[i][0] > h[j][0]
}
func (h mostTimeHeap) Swap(i, j int) {
	h[i], h[j] = h[j], h[i]
}
func (h *mostTimeHeap) Push(x interface{}) {
    *h = append(*h, x.([]int))
}
func (h *mostTimeHeap) Pop() interface{} {
	old := *h
	n := len(old)
	x := old[n-1]
	*h = old[0:n-1]
	return x
}

type byCloseDate [][]int
func (c byCloseDate) Len()int {
    return len(c)
}
func (c byCloseDate) Less(i, j int) bool {
    return c[i][1] < c[j][1]
}
func (c byCloseDate) Swap(i, j int) {
    c[i], c[j] = c[j], c[i]
}

func scheduleCourse(courses [][]int) int {
    sort.Sort(byCloseDate(courses))
    h := mostTimeHeap{}
    heap.Init(&h)
    sumTime := 0
    for _, course := range courses {
        heap.Push(&h, course)
        sumTime += course[0]
        if sumTime <= course[1] {
            continue
        }
        tmpCourse := heap.Pop(&h).([]int)
        sumTime -= tmpCourse[0]
    }
    return len(h)
}
