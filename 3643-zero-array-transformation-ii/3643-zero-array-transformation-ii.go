func minZeroArray(nums []int, queries [][]int) int {
    n, m := len(nums), len(queries)

    low, high := 0, m
    for low <= high {
        mid := (low + ((high - low) >> 1))

        if canMakeZero(nums, queries, mid, n, m) {
            high = mid - 1
        } else {
            low = mid + 1
        }
    }

    if low > m {
        return -1
    }
    return low
}

func canMakeZero(nums []int, queries [][]int, k, n, m int) bool {
    netDecrement := make([]int, n + 1)
    for i := 0; i < k; i++ {
        start, end, val := queries[i][0], queries[i][1], queries[i][2]
        netDecrement[start] += val
        netDecrement[end + 1] += -val
    }

    for i := 1; i < n + 1; i++ {
        netDecrement[i] += netDecrement[i - 1]
    }

    for i := 0; i < n; i++ {
        if nums[i] - netDecrement[i] > 0 {
            return false
        }
    }
    
    return true
}