class Solution {
    bool isPossible(vector<int>& nums, int n, int maxOperations, int maxBalls) {
        int totalOperations = 0;
        for (int i = 0; i < n; i++) {
            totalOperations += ceil(nums[i] / (double)maxBalls) - 1;
            if (totalOperations > maxOperations) return false;
        }
        return true;
    }
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int n = nums.size(), largest = nums[0];

        for (int i = 1; i < n; i++) largest = max(largest, nums[i]);

        int low = 1, high = largest;
        while (low <= high) {
            int mid = low + ((high - low) >> 1);

            if (isPossible(nums, n, maxOperations, mid)) high = mid - 1;
            else low = mid + 1;
        }

        return low;
    }
};