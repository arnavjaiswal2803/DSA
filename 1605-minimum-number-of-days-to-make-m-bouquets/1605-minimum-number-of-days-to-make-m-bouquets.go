func minDays(bloomDay []int, m int, k int) int {
    totalFlowers := len(bloomDay)
    totalFlowersReq := int64(m) * int64(k)
    if int64(totalFlowers) < totalFlowersReq {
        return -1;
    }

    low, high := 1, int(1e9);
    for low <= high {
        mid := low + ((high - low) >> 1)

        if canMakeBouquets(bloomDay, totalFlowers, m, k, mid) {
            high = mid - 1
        } else {
            low = mid + 1
        }
    }

    return low
}

func canMakeBouquets(bloomDay []int, totalFlowers, reqBouquets, 
                flowersReqInBouquet, daysPassed int) bool {
    numBouquets := 0
    for start, end := 0, 0; end < totalFlowers; end++ {
        if bloomDay[end] > daysPassed {
            start = end + 1
            continue
        }

        flowersCount := end - start + 1
        if flowersCount == flowersReqInBouquet {
            numBouquets++
            if numBouquets == reqBouquets {
                return true
            }

            start = end + 1
        }
    }

    return false
}