class Solution {
    bool getBit(int num, int pos) { return ((num >> pos) & 1) != 0; }
public:
    int largestCombination(vector<int>& candidates) {
        vector<int> hash(32, 0);
        int maxFreq = 0, n = candidates.size();

        for (int candidate : candidates) {
            for (int j = 0; j < 32; j++) 
                if (getBit(candidate, j)) maxFreq = max(maxFreq, ++hash[j]);
        }

        return maxFreq;
    }
};