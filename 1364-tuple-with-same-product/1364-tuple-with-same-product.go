func tupleSameProduct(nums []int) int {
    n, ans, freq := len(nums), 0, make(map[int]int)

    for i := 0; i < n; i++ {
        for j := i + 1; j < n; j++ {
            freq[nums[i] * nums[j]]++
        }
    }

    for  _, val := range freq {
        if (val >= 2) {
            ans += (val * (val - 1) * 4)
        }
    }

    return ans;
}