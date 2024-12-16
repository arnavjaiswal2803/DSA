class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        int n = nums.size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> minHeap;
        vector<int> ans(n);

        for (int i = 0; i < n; i++) minHeap.push({nums[i], i});

        while (k--) {
            int minn = minHeap.top().first, idx = minHeap.top().second;
            minHeap.pop();
            minHeap.push({minn * multiplier, idx});
        }

        while (!minHeap.empty()) {
            int idx = minHeap.top().second, elem = minHeap.top().first;
            minHeap.pop();
            ans[idx] = elem;
        }

        return ans;
    }
};