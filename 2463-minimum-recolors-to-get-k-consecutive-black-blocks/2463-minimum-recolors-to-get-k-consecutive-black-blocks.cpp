class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int n = blocks.size(), whiteCount = 0, minWhiteCount = n;
        for (int i = 0; i < n; i++) {
            if (blocks[i] == 'W') whiteCount++;
            if (i - k >= 0 && blocks[i - k] == 'W') whiteCount--;
            if (i >= k - 1)  minWhiteCount = min(minWhiteCount, whiteCount);
        }
        return minWhiteCount;
    }
};