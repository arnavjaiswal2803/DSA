/**
 * @param {number[]} nums
 * @param {number} threshold
 * @return {number}
 */
var smallestDivisor = function(nums, threshold) {
    let high = 1e6, low = 1;
    while (low <= high) {
        const mid = (low + ((high - low) >> 1));

        if (isSumOfQuotientsWithinThreshold(nums, threshold, mid)) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return low;
};

function isSumOfQuotientsWithinThreshold(nums, threshold, divisor) {
    const n = nums.length;
    let sum = 0;
    for (let i = 0; i < n; i++) {
        sum += Math.ceil(nums[i] / divisor);
    }
    return sum <= threshold;
}