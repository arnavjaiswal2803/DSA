class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size(), isFirstRowZero = false;

        for (int row = 0; row < n; row++) {
            for (int col = 0; col < m; col++) {
                if (matrix[row][col] != 0) continue;
                matrix[0][col] = 0;
                row == 0 ? isFirstRowZero = true : matrix[row][0] = 0;
            }
        }

        for (int row = n - 1; row > 0; row--) {
            if (matrix[row][0] != 0) continue;
            for (int col = 1; col < m; col++) matrix[row][col] = 0;
        }

        for (int col = m - 1; col >= 0; col--) {
            if (matrix[0][col] != 0) continue;
            for (int row = 1; row < n; row++) matrix[row][col] = 0;
        }

        if (isFirstRowZero) {
            for (int col = 0; col < m; col++) matrix[0][col] = 0;
        }

    }
};