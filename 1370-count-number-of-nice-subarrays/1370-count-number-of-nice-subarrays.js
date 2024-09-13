/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var numberOfSubarrays = function(nums, k) {
    return countSubarrays(nums, k) - countSubarrays(nums, k - 1)
};

function countSubarrays(nums, k) {
    let left = 0, right = 0, oddCount = 0, count = 0;
    while (right < nums.length) {
        oddCount += (nums[right] & 1);
        while (oddCount > k) {
            oddCount -= (nums[left] & 1);
            left++;
        }
        count += right - left + 1;
        right++;
    }
    return count;
} 