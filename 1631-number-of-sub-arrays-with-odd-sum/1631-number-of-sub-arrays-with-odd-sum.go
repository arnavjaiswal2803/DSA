func numOfSubarrays(arr []int) int {
    const MOD = 1e9 + 7
    
    prefixSum, oddCount, evenCount := 0, 0, 1
    oddSubarraysCount := 0

    for _, val := range arr {
        prefixSum += val

        if (prefixSum & 1) == 1 {
            oddSubarraysCount += evenCount
            oddCount++
        } else {
            oddSubarraysCount += oddCount
            evenCount++
        }

        oddSubarraysCount %= MOD
    }

    return oddSubarraysCount
}