/**
 * @param {number[]} nums
 * @param {number[][]} queries
 * @return {number}
 */
var minZeroArray = function (nums, queries) {
    const n = nums.length, m = queries.length;

    let low = 0, high = m;
    while (low <= high) {
        const mid = (low + ((high - low) >> 1));

        if (canMakeZero(nums, queries, mid, n, m)) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    if (low > m) {
        return -1;
    }
    return low;
};

function canMakeZero(nums, queries, k, n, m) {
    const netDecrement = new Array(n + 1);
    for (let i = 0; i < n + 1; i++) netDecrement[i] = 0;

    for (let i = 0; i < k; i++) {
        const start = queries[i][0], end = queries[i][1], val = queries[i][2];
        netDecrement[start] += val;
        netDecrement[end + 1] += -val;
    }

    for (let i = 1; i < n + 1; i++) {
        netDecrement[i] += netDecrement[i - 1];
    }

    for (let i = 0; i < n; i++) {
        if (nums[i] - netDecrement[i] > 0) {
            return false;
        }
    }

    return true;
}