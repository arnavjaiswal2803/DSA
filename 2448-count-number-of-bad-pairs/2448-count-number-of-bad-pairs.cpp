class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        int n = nums.size();
        long long totalPairs = ((long long)n * (long long)(n - 1)) / 2, goodPairs = 0;
        unordered_map<int, long long> hash;

        for (int i = 0; i < n; i++) {
            if (hash.find(nums[i] - i) != hash.end()) goodPairs += hash[nums[i] - i];
            hash[nums[i] - i]++;
        }

        return totalPairs - goodPairs;
    }
};