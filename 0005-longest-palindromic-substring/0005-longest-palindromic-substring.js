/**
 * @param {string} s
 * @return {string}
 */
var longestPalindrome = function(s) {
    const n = s.length;
    let maxLen = 0, longestPalindromicSubstr = "";
    for (let i = 0; i < n; i++) {
        for (let j = i; j < n; j++) {
            if (isPalindrome(s, i, j)) {
                const currLen = j - i + 1;
                if (currLen > maxLen) {
                    maxLen = currLen;
                    longestPalindromicSubstr = s.slice(i, j + 1);
                }
            }
        }
    }
    return longestPalindromicSubstr;
};

const isPalindrome = (s, start, end) => {
    while (start < end) {
        if (s[start] != s[end]) return false;
        start++;
        end--;
    }
    return true;
};