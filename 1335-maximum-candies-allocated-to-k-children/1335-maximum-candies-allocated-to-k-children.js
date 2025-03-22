/**
 * @param {number[]} candies
 * @param {number} k
 * @return {number}
 */
var maximumCandies = function (candies, k) {
    const n = candies.length;
    let totalCandies = 0;

    for (let i = 0; i < n; i++) totalCandies += candies[i];
    if (totalCandies < k) return 0;

    let low = 1, high = parseInt(totalCandies / k);
    while (low <= high) {
        const mid = parseInt((low + high) / 2);

        if (canAllocate(candies, mid, k)) low = mid + 1;
        else high = mid - 1;
    }

    return high;
};

function canAllocate(candies, toAllot, children) {
    const n = candies.length;
    let pilesAlloted = 0;

    for (let i = 0; i < n; i++) {
        const pileSize = candies[i];
        pilesAlloted += parseInt(pileSize / toAllot);
        if (pilesAlloted >= children) return true;
    }

    return false;
}