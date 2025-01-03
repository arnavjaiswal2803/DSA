func waysToSplitArray(nums []int) int {
    n, validSplits, totalSum, currSum := len(nums), 0, 0, 0;

    for _, val := range nums {
        totalSum += val;
    }

    for i := 0; i < n - 1; i++ {
        currSum += nums[i];
        if 2 * currSum >= totalSum {
            validSplits++;
        }
    }

    return validSplits;
}