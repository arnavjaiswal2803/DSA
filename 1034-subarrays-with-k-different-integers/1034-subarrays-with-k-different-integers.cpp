class Solution {
    int subarraysWithUptoKDistinct(vector<int> &nums, int k) {
        if (k == 0) return 0;

        int n = nums.size(), start = 0, end = 0, count = 0, distinctIntCnt = 0;
        vector<int> freq(n + 1, 0);
        while (end < n) {
            freq[nums[end]]++;
            if (freq[nums[end]] == 1) distinctIntCnt++;
            while (distinctIntCnt > k) {
                freq[nums[start]]--;
                if (freq[nums[start]] == 0) distinctIntCnt--;
                start++;
            }
            count += end - start + 1;
            end++;
        }
        return count;
    }
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return subarraysWithUptoKDistinct(nums, k) - 
            subarraysWithUptoKDistinct(nums, k - 1);
    }
};