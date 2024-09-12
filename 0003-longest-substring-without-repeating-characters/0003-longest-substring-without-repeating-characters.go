func lengthOfLongestSubstring(str string) int {
    start, end, mapp, maxLen := 0, 0, make(map[byte]int), 0
    for end < len(str) {
        if val, ok := mapp[str[end]]; !ok || val < start {
            mapp[str[end]] = end
            maxLen = max(maxLen, end - start + 1)
            end++
        } else {
            start = val + 1
        }
    }
    return maxLen
}