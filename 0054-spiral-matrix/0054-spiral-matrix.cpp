class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        int left = 0, right = n - 1, top = 0, bottom = m - 1;
        vector<int> ans;

        while (left <= right && top <= bottom) {
            for (int col = left; col <= right; col++) {
                ans.push_back(matrix[top][col]);
            }
            if (++top > bottom) break;

            for (int row = top; row <= bottom; row++) {
                ans.push_back(matrix[row][right]);
            }
            if (--right < left) break;

            for (int col = right; col >= left; col--) {
                ans.push_back(matrix[bottom][col]);
            }
            if (--bottom < top) break;

            for (int row = bottom; row >= top; row--) {
                ans.push_back(matrix[row][left]);
            }
            left++;
        }

        return ans;
    }
};