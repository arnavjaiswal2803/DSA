/**
 * @param {string} s
 * @return {string}
 */
var clearDigits = function(s) {
    const n = s.length;
    let skip = 0, ans = "";

    for (let i = n - 1; i >= 0; i--) {
        if (isDigit(s[i])) skip++;
        else if (skip == 0) ans += s[i];
        else skip--;
    }

    return ans.split("").reverse().join("");
};

function isDigit(ch) {
    return ch >= '0' && ch <= '9';
}