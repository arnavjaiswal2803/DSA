/**
 * @param {string} s
 * @return {number}
 */
var lengthOfLongestSubstring = function(str) {
    let start = 0, end = 0, maxLen = 0, mapp = {};
    while (end < str.length) {
        if (!mapp.hasOwnProperty(str[end]) || mapp[str[end]] < start) {
            mapp[str[end]] = end;
            maxLen = Math.max(maxLen, end - start + 1);
            end++;
        } else {
            start = mapp[str[end]] + 1;
        }
    }
    return maxLen;
};