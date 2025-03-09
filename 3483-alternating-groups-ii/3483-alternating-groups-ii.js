/**
 * @param {number[]} colors
 * @param {number} k
 * @return {number}
 */
var numberOfAlternatingGroups = function(colors, k) {
    const n = colors.length;
    let matchingCnt = 0, alterGrpCnt = 0;
    for (let start = 0, end = 1; end <= n + k - 2; end++) {
        if (colors[end % n] === colors[(end - 1) % n])
            matchingCnt = matchingCnt === 0 ? 2 : matchingCnt + 1;
        if (end - start + 1 > k) {
            if (colors[start] === colors[start + 1])
                matchingCnt = matchingCnt === 2 ? 0 : matchingCnt - 1;
            start++;
        }
        if (end - start + 1 === k && matchingCnt === 0) alterGrpCnt++;
    }
    return alterGrpCnt;
};