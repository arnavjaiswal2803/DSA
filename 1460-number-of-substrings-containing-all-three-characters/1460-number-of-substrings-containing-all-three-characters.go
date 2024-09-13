func numberOfSubstrings(s string) int {
    count, lastSeen := 0, []int{-1, -1, -1}
    for i := 0; i < len(s); i++ {
        lastSeen[s[i] - 'a'] = i
        count += 1 + min(lastSeen[0], lastSeen[1], lastSeen[2])
    }
    return count
}