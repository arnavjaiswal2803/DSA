class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n = nums.size();

        vector<int>rightMax(n);
        rightMax[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--) rightMax[i] = max(nums[i], rightMax[i + 1]);

        int left = 0, right = 0, maxRamp = 0;
        while (right < n) {
            while (left < right && nums[left] > rightMax[right]) left++;
            maxRamp = max(maxRamp, right - left);
            right++;
        }

        return maxRamp;
    }
};