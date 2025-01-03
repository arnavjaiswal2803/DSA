/**
 * @param {number[]} nums
 * @return {number}
 */
var waysToSplitArray = function(nums) {
    let n = nums.length, validSplits = 0, currSum = 0, totalSum = 0;

    for (let i = 0; i < n; i++) {
        totalSum += nums[i];
    }

    for (let i = 0; i < n - 1; i++) {
        currSum += nums[i];
        if (2 * currSum >= totalSum) validSplits++;
    }

    return validSplits;
};