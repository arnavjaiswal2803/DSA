/**
 * @param {number[]} nums
 * @return {number}
 */
var minimumIndex = function(nums) {
    const n = nums.length;
    const dominantElem = findDominantElement(nums, n);

    const prefixFreq = new Array(n);
    prefixFreq[0] = nums[0] === dominantElem ? 1 : 0;
    for (let i = 1; i < n; i++) {
        prefixFreq[i] = prefixFreq[i - 1] + (nums[i] === dominantElem ? 1 : 0);
    }

    for (let i = 0; i < n - 1; i++) {
        // first subarray
        const size1 = i + 1, dominantElemFreq1 = prefixFreq[i];
        if (dominantElemFreq1 <= parseInt(size1 / 2)) continue;

        // second subarray
        const size2 = n - i - 1;
        const dominantElemFreq2 = prefixFreq[n - 1] - prefixFreq[i];
        if (dominantElemFreq2 <= parseInt(size2 / 2)) continue;

        return i;
    }

    return -1;
};

function findDominantElement(nums, n) {
    let count = 0, dominantElem;
    for (let i = 0; i < n; i++) {
        if (count === 0) {
            dominantElem = nums[i];
            count++;
        } else if (nums[i] === dominantElem) {
            count++;
        } else {
            count--;
        }
    }
    return dominantElem;
}