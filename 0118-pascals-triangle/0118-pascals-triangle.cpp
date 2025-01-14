class Solution {
    vector<int> getNthRow(int rowIndex) {
        vector<int> row = {1};
        long long res = 1;
        for (int c = 0; c < rowIndex; c++) {
            res *= (rowIndex - c);
            res /= (c + 1);
            row.push_back(res);
        }
        return row;
    }
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> pascal;
        for (int i = 0; i < numRows; i++) pascal.push_back(getNthRow(i));
        return pascal;
    }
};