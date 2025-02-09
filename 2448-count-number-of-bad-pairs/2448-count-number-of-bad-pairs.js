/**
 * @param {number[]} nums
 * @return {number}
 */
var countBadPairs = function(nums) {
    const n = nums.length, totalPairs = ((n * (n - 1)) / 2);
    let goodPairs = 0;
    const hash = {};

    for (let i = 0; i < n; i++) {
        const val = nums[i] - i;
        if (hash.hasOwnProperty(val)) {
            goodPairs += hash[val];
        }
        hash[val] = hash.hasOwnProperty(val) ? hash[val] + 1 : 1;
    }

    return totalPairs - goodPairs;
};