class Solution {
    bool areRowsIdentical(vector<int> &r1, vector<int> &r2, int n) {
        for (int i = 0; i < n; i++) if (r1[i] != r2[i]) return false;
        return true;
    }

    bool areRowsOpposite(vector<int> &r1, vector<int> &r2, int n) {
        for (int i = 0; i < n; i++) if (r1[i] != (r2[i] ^ 1)) return false;
        return true;
    }
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size(), maxIdenticalRows = 1;

        for (int i = 0; i < m - 1; i++) {
            int identicalRowCount = 1;
            for (int j = i + 1; j < m; j++) {
                if (areRowsIdentical(matrix[i], matrix[j], n) || 
                    areRowsOpposite(matrix[i], matrix[j], n)) identicalRowCount++;
            }
            maxIdenticalRows = max(maxIdenticalRows, identicalRowCount);
        }

        return maxIdenticalRows;
    }
};