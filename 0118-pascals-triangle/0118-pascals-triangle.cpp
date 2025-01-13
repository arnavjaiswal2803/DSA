class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> pascal;
        for (int i = 1; i <= numRows; i++) {
            vector<int> currRow(i, 1);
            for (int j = 1; j < i - 1; j++) {
                currRow[j] = pascal[i - 1 - 1][j - 1] + pascal[i - 1 - 1][j];
            }
            pascal.push_back(currRow);
        }
        return pascal;
    }
};