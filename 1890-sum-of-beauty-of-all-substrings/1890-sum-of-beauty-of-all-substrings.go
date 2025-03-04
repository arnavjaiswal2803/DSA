func beautySum(s string) int {
    n, beautySum := len(s), 0
    for i := 0; i < n; i++ {
        for j := i; j < n; j++ {
            beautySum += getBeauty(&s, i, j)
        }
    }
    return beautySum
}

func getBeauty(s *string, start, end int) int {
    n, freq := len(*s), make([]int, 26)
    for i := start; i <= end; i++ {
        freq[(*s)[i] - 'a']++
    }

    maxFreq, leastFreq := 0, n
    for i := 0; i < 26; i++ {
        maxFreq = max(maxFreq, freq[i])
        if (freq[i] > 0 && (leastFreq == n || freq[i] < leastFreq)) {
            leastFreq = freq[i]
        }
    }

    return maxFreq - leastFreq
}