class Solution {
public:
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        return canMakeHorizontalCuts(rectangles) ||
               canMakeVerticalCuts(rectangles);
    }

private:
    bool canMakeHorizontalCuts(vector<vector<int>>& rectangles) {
        int m = rectangles.size();

        // sorting according to y-start
        sort(rectangles.begin(), rectangles.end(),
             [](vector<int>& a, vector<int>& b) { return a[1] < b[1]; });

        int cuts = 0, maxEnd = rectangles[0][3];
        for (int i = 1; i < m; i++) {
            if (maxEnd <= rectangles[i][1]) {
                cuts++;
                if (cuts >= 2) return true;
            }
            maxEnd = max(maxEnd, rectangles[i][3]);
        }
        return false;
    }

    bool canMakeVerticalCuts(vector<vector<int>>& rectangles) {
        int m = rectangles.size();

        // sorting according to x-start
        sort(rectangles.begin(), rectangles.end(),
             [](vector<int>& a, vector<int>& b) { return a[0] < b[0]; });

        int cuts = 0, maxEnd = rectangles[0][2];
        for (int i = 1; i < m; i++) {
            if (maxEnd <= rectangles[i][0]) {
                cuts++;
                if (cuts >= 2) return true;
            }
            maxEnd = max(maxEnd, rectangles[i][2]);
        }

        return false;
    }
};