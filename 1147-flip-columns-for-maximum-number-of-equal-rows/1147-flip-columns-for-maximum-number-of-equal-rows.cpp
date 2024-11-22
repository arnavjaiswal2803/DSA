class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size(), maxIdenticalRows = 1;
        unordered_map<string, int> freq;

        for (int i = 0; i < m; i++) {
            string pattern = "T";
            for (int j = 1; j < n; j++) 
                pattern += matrix[i][j] == matrix[i][0] ? "T" : "F";
            freq[pattern]++;
        }

        for (auto &patternFreq : freq) 
            maxIdenticalRows = max(maxIdenticalRows, patternFreq.second);

        return maxIdenticalRows;
    }
};