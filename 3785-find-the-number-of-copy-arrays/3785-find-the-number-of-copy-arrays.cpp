class Solution {
public:
    int countArrays(vector<int>& original, vector<vector<int>>& bounds) {
        int n = original.size(), high = bounds[0][1], low = bounds[0][0];
        int ans = high - low + 1;

        for (int i = 1; i < n; i++) {
            int diff = original[i] - original[i - 1];
            high = min(high + diff, bounds[i][1]);
            low = max(low + diff, bounds[i][0]);
            ans = high - low + 1;
        }

        return max(ans, 0);
    }
};