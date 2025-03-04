func beautySum(s string) int {
	n, beautySum := len(s), 0
	for i := 0; i < n; i++ {
		freq := make([]int, 26)
		for j := i; j < n; j++ {
			freq[s[j]-'a']++
            
			maxFreq, leastFreq := 0, n
			for i := 0; i < 26; i++ {
				maxFreq = max(maxFreq, freq[i])
				if freq[i] > 0 && (leastFreq == n || freq[i] < leastFreq) {
					leastFreq = freq[i]
				}
			}

			beautySum += maxFreq - leastFreq
		}
	}
	return beautySum
}