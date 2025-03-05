/**
 * @param {number} n
 * @return {number}
 */
var coloredCells = function(n) {
    let count = 1, commonDiff = 0;
    for (let i = 2; i <= n; i++) {
        commonDiff += 4;
        count += commonDiff;
    }
    return count;
};