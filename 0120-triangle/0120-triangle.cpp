class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> prev(n);

        for (int row = n - 1; row >= 0; row--) {
            vector<int> curr(n);
            for (int col = 0; col <= row; col++) {
                curr[col] = triangle[row][col];
                if (row < n - 1) 
                    curr[col] += min(prev[col], prev[col + 1]);
            }
            prev = curr;
        }

        return prev[0];
    }
};