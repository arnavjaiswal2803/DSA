func minimumOperations(nums []int) int {
    n := len(nums)
    freq, duplicates, operations := make(map[int]int), make(map[int]struct{}), 0

    for i := 0; i < n; i++ {
        if freq[nums[i]] == 1 {
            duplicates[nums[i]] = struct{}{}
        }
        freq[nums[i]]++
    }

    for i := 0; i < n && len(duplicates) > 0; {
        for j := 0; j < 3 && i < n; j++ {
            freq[nums[i]]--
            if freq[nums[i]] == 1 {
                if _, ok := duplicates[nums[i]]; ok {
                    delete(duplicates, nums[i])
                }
            }
            i++
        }
        operations++
    }

    return operations
}