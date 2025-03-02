/**
 * @param {number[]} bloomDay
 * @param {number} m
 * @param {number} k
 * @return {number}
 */
var minDays = function(bloomDay, m, k) {
    const totalFlowers = bloomDay.length;
    const totalFlowersReq = m * k;
    if (totalFlowers < totalFlowersReq) {
        return -1;
    }

    let low = 1, high = 1e9;
    while (low <= high) {
        const mid = (low + ((high - low) >> 1));

        if (canMakeBouquets(bloomDay, totalFlowers, m, k, mid)) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return low;
};

function canMakeBouquets(bloomDay, totalFlowers, reqBouquets, 
                flowersReqInBouquet, daysPassed) {
    let numBouquets = 0;
    for (let start = 0, end = 0; end < totalFlowers; end++) {
        if (bloomDay[end] > daysPassed) {
            start = end + 1;
            continue;
        }

        const flowersCount = end - start + 1;
        if (flowersCount === flowersReqInBouquet) {
            numBouquets++;
            if (numBouquets === reqBouquets) {
                return true;
            }

            start = end + 1;
        }
    }

    return false;
}