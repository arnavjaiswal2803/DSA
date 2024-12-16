class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        int n = nums.size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> minHeap;
        vector<int> ans(nums);

        for (int i = 0; i < n; i++) minHeap.push({nums[i], i});

        while (k--) {
            int minn = minHeap.top().first, idx = minHeap.top().second;
            minHeap.pop();

            ans[idx] = minn * multiplier;

            minHeap.push({minn * multiplier, idx});
        }

        return ans;
    }
};