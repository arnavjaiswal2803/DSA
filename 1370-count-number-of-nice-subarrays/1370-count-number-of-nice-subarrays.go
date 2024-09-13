func numberOfSubarrays(nums []int, k int) int {
    return countSubarrays(nums, k) - countSubarrays(nums, k - 1)
}

func countSubarrays(nums []int, k int) int {
    left, right, oddCount, count := 0, 0, 0, 0
    for right < len(nums) {
        oddCount += (nums[right] & 1)
        for oddCount > k {
            oddCount -= (nums[left] & 1)
            left++
        }
        count += right - left + 1
        right++
    }
    return count
} 