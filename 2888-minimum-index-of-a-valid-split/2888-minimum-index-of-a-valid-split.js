/**
 * @param {number[]} nums
 * @return {number}
 */
var minimumIndex = function(nums) {
    const n = nums.length;
    const dominantElem = findDominantElement(nums, n);

    let dominantElemFreq = 0;
    for (let i = 0; i < n; i++) {
        if (nums[i] === dominantElem) {
            dominantElemFreq++;
        }
    }

    let freqTillI = 0;
    for (let i = 0; i < n - 1; i++) {
        // first subarray
        const size1 = i + 1;
        if (nums[i] === dominantElem) {
            freqTillI++;
        }
        if (freqTillI <= parseInt(size1 / 2)) continue;

        // second subarray
        const size2 = n - i - 1;
        const dominantElemFreq2 = dominantElemFreq - freqTillI;
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