func maximumCount(nums []int) int {
    posCnt, negCnt := 0, 0
    for _, val := range nums {
        if val < 0 {
            negCnt++
        } else if val > 0 {
            posCnt++
        }
    }
    return max(posCnt, negCnt)
}