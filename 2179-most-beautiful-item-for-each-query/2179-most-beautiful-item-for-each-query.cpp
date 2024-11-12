class Solution {
    int binarySearch(vector<vector<int>> &maxBeauty, int target) {
        if (target < maxBeauty[0][0]) return 0;

        int low = 0, high = maxBeauty.size() - 1;
        while (low <= high) {
            int mid = low + ((high - low) >> 1);

            if (maxBeauty[mid][0] == target) return maxBeauty[mid][1];
            else if (maxBeauty[mid][0] < target) low = mid + 1;
            else high = mid - 1;
        }
        return maxBeauty[high][1];
    }
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        int n = items.size(), m = queries.size();

        sort(items.begin(), items.end(), [&](vector<int> &a, vector<int> &b) {
            if (a[0] < b[0]) return true;
            else if (a[0] > b[0]) return false;
            else return a[1] > b[1];
        });

        vector<vector<int>> maxBeauty = { items[0] };
        for (int i = 1; i < n; i++) {
            if (items[i][0] != items[i - 1][0]) {
                vector<int> temp = { items[i][0], 
                    max(maxBeauty.back()[1], items[i][1]) };
                maxBeauty.push_back(temp);
            }
        }

        vector<int> ans(m);
        for (int i = 0; i < m; i++) ans[i] = binarySearch(maxBeauty, queries[i]);

        return ans;
    }
};