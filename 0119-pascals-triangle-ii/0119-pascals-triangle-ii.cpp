class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> prev;
        for (int i = 1; i <= rowIndex + 1; i++) {
            vector<int> currRow(i, 1);
            for (int j = 1; j < i - 1; j++) {
                currRow[j] = prev[j - 1] + prev[j];
            }
            if (i - 1 == rowIndex) return currRow;
            prev = currRow;
        }
        return {};
    }
};