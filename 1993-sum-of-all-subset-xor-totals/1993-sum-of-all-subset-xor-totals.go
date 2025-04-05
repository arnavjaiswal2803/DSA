func subsetXORSum(nums []int) int {
    n, xorTotalSum := len(nums), 0
    getXorTotalSum(nums, n - 1, 0, &xorTotalSum)
    return xorTotalSum
}

func getXorTotalSum(nums []int, idx, xorTotal int, xorTotalSum *int) {
    if idx < 0 {
        *xorTotalSum += xorTotal
        return
    }

    getXorTotalSum(nums, idx - 1, xorTotal, xorTotalSum)
    getXorTotalSum(nums, idx - 1, xorTotal ^ nums[idx], xorTotalSum)
}