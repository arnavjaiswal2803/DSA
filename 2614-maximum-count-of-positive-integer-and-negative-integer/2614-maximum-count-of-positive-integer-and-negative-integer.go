func maximumCount(nums []int) int {
    n := len(nums)
    posCnt := n - getFirstOccurenceOfPositive(nums)
    negCnt := 1 + getLastOccurenceOfNegative(nums)
    return max(posCnt, negCnt)
}

func getLastOccurenceOfNegative(nums []int) int {
    low, high := 0, len(nums) - 1
    for low <= high {
        mid := (low + ((high - low) >> 1))

        if nums[mid] < 0 {
            low = mid + 1
        } else {
            high = mid - 1
        }
    }
    return high
}

func getFirstOccurenceOfPositive(nums []int) int {
    low, high := 0, len(nums) - 1
    for low <= high {
        mid := (low + ((high - low) >> 1))

        if nums[mid] > 0 {
            high = mid - 1
        } else {
            low = mid + 1
        }
    }
    return low
}