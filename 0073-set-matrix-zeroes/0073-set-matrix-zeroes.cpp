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
            for (int col = m - 1; col > 0; col--) {
                if (matrix[row][col] == 0) continue;
                if (matrix[row][0] == 0|| matrix[0][col] == 0) matrix[row][col] = 0;
            }
        }

        if (matrix[0][0] == 0) {
            for (int row = 1; row < n; row++) matrix[row][0] = 0;
        }

        if (isFirstRowZero) {
            for (int col = 0; col < m; col++) matrix[0][col] = 0;
        }
    }
};