/**
 * @param {string} s
 * @return {number}
 */
var numberOfSubstrings = function(s) {
    let count = 0, aLastSeen = -1, bLastSeen = -1, cLastSeen = -1;
    for (let i = 0; i < s.length; i++) {
        if (s[i] === "a") {
            aLastSeen = i;
        } else if (s[i] === "b") {
            bLastSeen = i;
        } else {
            cLastSeen = i;
        }
        count += 1 + Math.min(aLastSeen, bLastSeen, cLastSeen);
    }
    return count;
};