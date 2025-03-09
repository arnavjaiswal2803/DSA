func numberOfAlternatingGroups(colors []int, k int) int {
    n, matchingCnt, alterGrpCnt := len(colors), 0, 0
    for start, end := 0, 1; end <= n + k - 2; end++ {
        if colors[end % n] == colors[(end - 1) % n] {
            if matchingCnt == 0 {
                matchingCnt = 2
            } else {
                matchingCnt++
            }
        }
        if end - start + 1 > k {
            if colors[start] == colors[start + 1] {
                if matchingCnt > 2 {
                    matchingCnt--
                } else {
                    matchingCnt = 0
                }
            }
            start++
        }
        if end - start + 1 == k && matchingCnt == 0 {
            alterGrpCnt++
        }
    }
    return alterGrpCnt
}