func maximumTripletValue(nums []int) int64 {
    n := len(nums)
    maxI, maxDiff, maxVal := int64(0), int64(0), int64(0)
    for k := 0; k < n; k++ {
        maxVal = max(maxVal, maxDiff * int64(nums[k]))
        maxDiff = max(maxDiff, maxI - int64(nums[k]))
        maxI = max(maxI, int64(nums[k]))
    }
    return maxVal
}