class Solution {
typedef pair<long long, int> pii;
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size(), minLen = INT_MAX;
        long long sum = 0;
        priority_queue<pii, vector<pii>, greater<>> prefixSumHeap;

        for (int i = 0; i < n; i++) {
            sum += nums[i];
            if (sum >= k) minLen = min(minLen, i + 1);
            while (!prefixSumHeap.empty() && sum - prefixSumHeap.top().first >= k) {
                minLen = min(minLen, i - prefixSumHeap.top().second);
                prefixSumHeap.pop();
            }
            prefixSumHeap.push({sum, i});
        }

        return minLen == INT_MAX ? -1 : minLen;
    }
};