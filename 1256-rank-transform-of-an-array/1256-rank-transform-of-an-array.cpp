class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size(), rank = 1;
        vector<int> ans(arr);
        if (n == 0) return ans;
        map<int, int> rankMap;

        sort(ans.begin(), ans.end());
        rankMap[ans[0]] = rank;
        for (int i = 1; i < n; i++) 
            rankMap[ans[i]] = ans[i] == ans[i - 1] ? rank : ++rank;
        for (int i = 0; i < n; i++) ans[i] = rankMap[arr[i]];

        return ans; 
    }
};