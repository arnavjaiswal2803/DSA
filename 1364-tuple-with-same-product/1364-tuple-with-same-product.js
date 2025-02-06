/**
 * @param {number[]} nums
 * @return {number}
 */
var tupleSameProduct = function(nums) {
    const n = nums.length;
    let ans = 0;
    const freq = {};

    for (let i = 0; i < n; i++) {
        for (let j = i + 1; j < n; j++) {
            const prod = nums[i] * nums[j];
            freq[prod] = freq.hasOwnProperty(prod) ? freq[prod] + 1 : 1;
        }
    }

    for (let prod in freq) {
        if (freq[prod] >= 2) {
            ans += (freq[prod] * (freq[prod] - 1) * 4);
        }
    }

    return ans;
};