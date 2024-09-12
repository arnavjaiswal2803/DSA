/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var longestOnes = function(nums, k) {
    let left = 0, right = 0, maxLen = 0, allowedZeroes = 0;
    while (right < nums.length) {
        if (nums[right] === 0) {
            allowedZeroes++;
        }
        if (allowedZeroes <= k) {
            maxLen = Math.max(maxLen, right - left + 1);
        } else {
            if (nums[left] == 0) {
                allowedZeroes--;
            }
            left++;
        }
        right++;
    }
    return maxLen;
};