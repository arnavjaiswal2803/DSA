class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        int n = items.size(), m = queries.size();

        sort(items.begin(), items.end(), [&](vector<int> &a, vector<int> &b) {
            return a[0] < b[0];
        });

        vector<pair<int, int>> queriesWithIndices;
        for (int i = 0; i < m; i++) queriesWithIndices.push_back({queries[i], i});
        sort(queriesWithIndices.begin(), queriesWithIndices.end());

        vector<int> ans(m);
        int itemIndex = 0, maxBeauty = 0;
        for (int i = 0; i < m; i++) {
            int query = queriesWithIndices[i].first;
            int originalIndex = queriesWithIndices[i].second;

            while (itemIndex < n && items[itemIndex][0] <= query) {
                maxBeauty = max(maxBeauty, items[itemIndex][1]);
                itemIndex++;
            }
            ans[originalIndex] = maxBeauty;
        }

        return ans;
    }
};