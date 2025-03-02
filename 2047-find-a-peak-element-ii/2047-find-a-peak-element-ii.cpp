class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();

        int low = 0, high = n - 1;
        while (low <= high) {
            int mid = (low + ((high - low) >> 1));

            int row = findMaxEle(mat, m, mid);

            int left = mid - 1 >= 0 ? mat[row][mid - 1] : -1;
            int right = mid + 1 < n ? mat[row][mid + 1] : -1;

            if (mat[row][mid] > left && mat[row][mid] > right) {
                return {row, mid};
            } else if (mat[row][mid] < left) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return {-1, -1};
    }

private:
    int findMaxEle(vector<vector<int>> &mat, int m, int col) {
        int maxRow = 0;
        for (int i = 1; i < m; i++) {
            if (mat[i][col] > mat[maxRow][col]) maxRow = i;
        }
        return maxRow;
    }
};