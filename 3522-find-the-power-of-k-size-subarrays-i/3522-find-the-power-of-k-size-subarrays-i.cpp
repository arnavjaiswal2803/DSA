class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int> dq;
        vector<int> ans(n - k + 1);

        for (int i = 0; i < n; i++) {
            if (!dq.empty() && nums[i] != nums[dq.back()] + 1) dq.clear();
            dq.push_back(i);
            if (i >= k - 1) ans [i - k + 1] = dq.size() == k ? nums[dq.back()] : -1;
            if (dq.size() == k) dq.pop_front();
        }

        return ans;
    }
};