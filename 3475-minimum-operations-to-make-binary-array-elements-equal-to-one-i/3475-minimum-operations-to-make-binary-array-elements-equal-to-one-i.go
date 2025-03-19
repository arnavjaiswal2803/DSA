func minOperations(nums []int) int {
    n, dupNums, operations := len(nums), nums, 0

    for i := 0; i <= n - 3; i++ {
        if dupNums[i] == 1 {
            continue
        }
        dupNums[i] ^= 1
        dupNums[i + 1] ^= 1
        dupNums[i + 2] ^= 1

        operations++
    }
    if dupNums[n - 1] == 0 || dupNums[n - 2] == 0 {
        return -1
    }
    
    return operations
}