class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n = values.size(), maxLeft = values[0], maxScore = -1e9;
        
        for (int i = 1; i < n; i++) {
            int currRight = values[i] - i;
            maxScore = max(maxScore, maxLeft + currRight);

            int currLeft = values[i] + i;
            maxLeft = max(maxLeft, currLeft);
        }

        return maxScore;
    }
};