class Solution {
public:
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        return canMakeTwoCuts(rectangles, 0) ||
               canMakeTwoCuts(rectangles, 1);
    }

private:
    bool canMakeTwoCuts(vector<vector<int>>& rectangles, int dim) {
        int m = rectangles.size();

        sort(rectangles.begin(), rectangles.end(),
             [dim](vector<int>& a, vector<int>& b) { return a[dim] < b[dim]; });

        int cuts = 0, maxEnd = rectangles[0][dim + 2];
        for (int i = 1; i < m; i++) {
            if (maxEnd <= rectangles[i][dim]) {
                cuts++;
                if (cuts >= 2) return true;
            }
            maxEnd = max(maxEnd, rectangles[i][dim + 2]);
        }
        return false;
    }
};