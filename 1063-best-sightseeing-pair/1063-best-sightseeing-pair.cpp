class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n = values.size(), maxLeft = values[0], maxScore = -1e9;
        
        for (int i = 1; i < n; i++) {
            int currScore = maxLeft + values[i] - i;
            maxScore = max(maxScore, currScore);
            maxLeft = max(maxLeft, values[i] + i);
        }

        return maxScore;
    }
};