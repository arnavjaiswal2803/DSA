typedef long long ll;
class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int m = grid.size();
        const int n = m * m;

        long long sum = 0, firstNSum = (n * (n + 1)) / 2;
        long long sqSum = 0, firstNSqSum = ((ll)n * (n + 1) * (2 * n + 1)) / 6;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < m; j++) {
                sum += grid[i][j];
                sqSum += (grid[i][j] * grid[i][j]);
            }
        }

        int aMinusB = sum - firstNSum;
        int aPlusB = (sqSum - firstNSqSum) / aMinusB;
        int a = (aMinusB + aPlusB) / 2;
        int b = aPlusB - a;

        return {a, b};
    }
};