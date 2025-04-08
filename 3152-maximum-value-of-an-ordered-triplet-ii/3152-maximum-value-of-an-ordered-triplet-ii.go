func maximumTripletValue(nums []int) int64 {
	n := len(nums)
	prefixMax, suffixMax := make([]int, n), make([]int, n)

	prefixMax[0] = nums[0]
	for i := 1; i < n; i++ {
		prefixMax[i] = max(prefixMax[i-1], nums[i])
	}

	suffixMax[n-1] = nums[n-1]
	for i := n - 2; i >= 0; i-- {
		suffixMax[i] = max(suffixMax[i+1], nums[i])
	}

	maxVal := int64(0)
	for i := 1; i < n-1; i++ {
		maxVal = max(maxVal,
			(int64(prefixMax[i-1])-int64(nums[i]))*int64(suffixMax[i+1]))
	}

	return maxVal
}