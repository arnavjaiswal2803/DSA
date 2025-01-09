class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;

        sort(nums.begin(), nums.end());
        int len = 1, maxLen = 1;
        for (int i = 1; i < n; i++) {
            if ((long)nums[i - 1] + (long)1 == (long)nums[i]) {
                len++;
                maxLen = max(maxLen, len);
            } else if (nums[i - 1] != nums[i]) len = 1;
        }

        return maxLen;
    }
};