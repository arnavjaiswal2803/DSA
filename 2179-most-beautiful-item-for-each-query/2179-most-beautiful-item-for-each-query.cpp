class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        int n = items.size(), m = queries.size();
        vector<int> ans(m, 0);
        map<int, int> maxiBeauty;

        sort(items.begin(), items.end(), [&](vector<int> &a, vector<int> &b) {
            if (a[0] < b[0]) return true;
            else if (a[0] > b[0]) return false;
            else return a[1] > b[1];
        });

        for (int i = 0; i < m; i++) ans[i] = maxiBeauty[queries[i]] = 0;

        for (int i = 0; i < n; i++) {
            if (i == 0 || items[i][0] != items[i - 1][0]) 
                maxiBeauty[items[i][0]] = items[i][1];
        }

        int maxBeautyTillCurrPrice = 0;
        for(auto &it : maxiBeauty) {
            maxBeautyTillCurrPrice = max(maxBeautyTillCurrPrice, it.second);
            maxiBeauty[it.first] = maxBeautyTillCurrPrice;
        }

        for (int i = 0; i < m; i++) ans[i] = maxiBeauty[queries[i]];

        return ans;
    }
};