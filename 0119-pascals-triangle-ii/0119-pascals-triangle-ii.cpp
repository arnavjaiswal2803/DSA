class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> row = {1};
        long long res = 1;
        for (int c = 0; c < rowIndex; c++) {
            res *= (rowIndex - c);
            res /= (c + 1);
            row.push_back(res);
        }
        return row;
    }
};