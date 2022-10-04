func subdomainVisits(cpdomains []string) []string {
	cnt := make(map[string]int)
	for _, s := range cpdomains {
		lst := strings.Split(s, " ")
		n, _ := strconv.Atoi(lst[0])
		l := lst[1]
		i := strings.Index(l, ".")
		for i != -1 {
			cnt[l] += n
			l = l[i+1:]
			i = strings.Index(l, ".")
		}
        cnt[l] += n
	}
	ret := make([]string, 0, len(cnt))
	for k, v := range cnt {
		str := strconv.Itoa(v) + " " + k
		ret = append(ret, str)
	}
	return ret
}
