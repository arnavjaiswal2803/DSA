func queryResults(limit int, queries [][]int) []int {
    n := len(queries)
    ans := make([]int, n)
    ballColorMap, colorFreq := make(map[int]int), make(map[int]int)

    for i := 0; i < n; i++ {
        ball, color := queries[i][0], queries[i][1]

        if prevColor, ok := ballColorMap[ball]; ok {
            colorFreq[prevColor]--;
            if (colorFreq[prevColor] == 0) {
                delete (colorFreq, prevColor)
            }
        }

        ballColorMap[ball] = color
        colorFreq[color]++

        ans[i] = len(colorFreq)
    }


    return ans
}