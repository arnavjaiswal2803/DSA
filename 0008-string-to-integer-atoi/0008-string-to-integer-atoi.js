/**
 * @param {string} s
 * @return {number}
 */
var myAtoi = function(s) {
    const n = s.length, INT_MAX = 2147483647, INT_MIN = -2147483648;
    let i = 0, isNegative = false, parsedNum = 0;

    while (i < n && s[i] === " ") i++;
    if (i === n) return 0;

    if (s[i] === "-" || s[i] === "+") {
        if (s[i] === "-") isNegative = true;
        i++;
    }

    while (i < n && s[i] >= "0" && s[i] <= "9") {
        parsedNum = parsedNum * 10 + (s[i] - "0");

        if (!isNegative && parsedNum > INT_MAX) return INT_MAX;
        if (isNegative && parsedNum * -1 < INT_MIN) return INT_MIN;

        i++;
    }

    return isNegative ? parsedNum * -1 : parsedNum;
};