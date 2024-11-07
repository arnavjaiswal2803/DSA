class Solution {
    bool getBit(int num, int pos) { return ((num >> pos) & 1) != 0; }
public:
    int largestCombination(vector<int>& candidates) {
        int n = candidates.size(), maxCount = 0;

        for (int i = 0; i < 24; i++) {
            int count = 0;
            for (int candidate : candidates) if (getBit(candidate, i)) count++;
            maxCount = max(maxCount, count);
        }

        return maxCount;
    }
};