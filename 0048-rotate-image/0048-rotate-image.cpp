class Solution {
    void transpose(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
public:
    void rotate(vector<vector<int>>& matrix) {
        transpose(matrix);
        for (vector<int>& row : matrix) reverse(row.begin(), row.end());
    }
};