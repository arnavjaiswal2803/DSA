class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(nums);

        for (int i = 0; i < n - 1; i++) {
            if (ans[i] == ans[i + 1]) {
                ans[i] *= 2;
                ans[i + 1] = 0;
            }
        }

        for (int i = 0, j = -1; i < n; i++) {
            if (ans[i] != 0) continue;
            if (j < i) j = i + 1;
            while (j < n && ans[j] == 0) j++;
            if (j == n) break;
            swap(ans[i], ans[j]);
        }

        return ans;
    }
};