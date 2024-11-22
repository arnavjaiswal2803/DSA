class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size(), minLen = INT_MAX;
        long long sum = 0;

        vector<long long> prefixSum(n, 0);
        prefixSum[0] = nums[0];
        for (int i = 1; i < n; i++) prefixSum[i] = prefixSum[i - 1] + nums[i];

        deque<int> dq;
        for (int i = 0; i < n; i++) {
            if (prefixSum[i] >= k) minLen = min(minLen, i + 1);
            while (!dq.empty() && prefixSum[i] - prefixSum[dq.front()] >= k) {
                minLen = min(minLen, i - dq.front());
                dq.pop_front();
            }
            while (!dq.empty() && prefixSum[i] <= prefixSum[dq.back()]) dq.pop_back();
            dq.emplace_back(i);
        }

        return minLen == INT_MAX ? -1 : minLen;
    }
};