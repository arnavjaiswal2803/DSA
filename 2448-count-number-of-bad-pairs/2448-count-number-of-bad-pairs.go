func countBadPairs(nums []int) int64 {
    n := len(nums)
    totalPairs, goodPairs := int64((n * (n - 1)) / 2), int64(0)
    hash := make(map[int]int64)

    for i := 0; i < n; i++ {
        if freq, ok := hash[nums[i] - i]; ok {
            goodPairs += freq
        }
        hash[nums[i] - i]++
    }

    return totalPairs - goodPairs
}