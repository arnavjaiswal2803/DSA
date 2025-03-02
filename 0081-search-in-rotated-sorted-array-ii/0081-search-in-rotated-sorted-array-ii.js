/**
 * @param {number[]} nums
 * @param {number} target
 * @return {boolean}
 */
var search = function (nums, target) {
    const n = nums.length;
    let low = 0, high = n - 1;
    while (low <= high) {
        const mid = parseInt(low + ((high - low) / 2));

        if (nums[mid] === target) {
            return true;
        } else if (nums[low] === nums[mid] && nums[mid] === nums[high]) {
            low++;
            high--;
        } else if (nums[low] <= nums[mid]) {
            if (target >= nums[low] && target < nums[mid]) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        } else {
            if (target > nums[mid] && target <= nums[high]) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
    }

    return false;
};