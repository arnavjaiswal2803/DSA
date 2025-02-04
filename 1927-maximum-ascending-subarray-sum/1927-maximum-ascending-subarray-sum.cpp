class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int n = nums.size(), maxSum = nums[0], currSum = nums[0];

        for (int i = 1; i < n; i++) {
            if (nums[i] > nums[i - 1]) currSum += nums[i];
            else {
                maxSum = max(maxSum, currSum);
                currSum = nums[i];
            }
        }
        maxSum = max(maxSum, currSum);
        
        return maxSum;
    }
};