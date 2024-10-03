class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size(), minLen = n;
        long long totalSum = 0;

        for (int num : nums) totalSum += num;
        int targetRem = totalSum % p;
        if (targetRem == 0) return 0;

        long long prefixSum = 0;
        unordered_map<long long, int> prefixModIdx;
        prefixModIdx[0] = -1;
        for (int i = 0; i < n; i++) {
            prefixSum += nums[i];
            int currRem = prefixSum % p;
            int required = (currRem - targetRem + p) % p;
            
           if (prefixModIdx.find(required) != prefixModIdx.end()) {
                int len = i - prefixModIdx[required];
                minLen = min(minLen, len);
            }
            prefixModIdx[currRem] = i;
        }

        return minLen < n ? minLen : -1;
    }
};