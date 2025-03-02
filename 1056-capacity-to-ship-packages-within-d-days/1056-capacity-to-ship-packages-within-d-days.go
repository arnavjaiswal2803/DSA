func shipWithinDays(weights []int, days int) int {
    n, low, high := len(weights), 1, 0

    for i := 0; i < n; i++ {
        high += weights[i]
        low = max(low, weights[i])
    }

    for low <= high {
        mid := (low + ((high - low) >> 1))

        if canShipWithinDays(weights, n, days, mid) {
            high = mid - 1
        } else {
            low = mid + 1
        }
    }

    return low
}

func canShipWithinDays(weights []int, n, days, capacity int) bool {
    sum, reqDays := 0, 1
    for i := 0; i < n; i++ {
        if weights[i] + sum > capacity {
            reqDays++
            if reqDays > days {
                return false
            }
            sum = 0
        }
        sum += weights[i]
    }
    return true
}