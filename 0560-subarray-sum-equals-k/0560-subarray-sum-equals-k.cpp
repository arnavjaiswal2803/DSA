class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size(), ans = 0;
        unordered_map<long, int> freq;
        long sum = 0;

        for (int i = 0; i < n; i++) {
            sum += nums[i];
            if (sum == k) ans++;
            if (freq.find(sum - k) != freq.end()) ans += freq[sum - k];
            freq[sum]++;
        }

        return ans;
    }
};