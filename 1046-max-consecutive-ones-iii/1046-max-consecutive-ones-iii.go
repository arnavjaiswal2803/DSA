func longestOnes(nums []int, k int) int {
    left, right, maxLen, allowedZeroes := 0, 0, 0, 0
    for right < len(nums) {
        if nums[right] == 0 {
            allowedZeroes++
        }
        if allowedZeroes <= k {
            maxLen = max(maxLen, right - left + 1)
        } else {
            if nums[left] == 0 {
                allowedZeroes--
            }
            left++
        }
        right++
    }
    return maxLen
}