class Solution {
public:
    int minCapability(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> numsCopy(nums);

        sort(numsCopy.begin(), numsCopy.end());

        int low = 0, high = n - 1;
        while (low <= high) {
            int mid = (low + ((high - low) >> 1));

            if (canSteal(nums, k, numsCopy[mid])) high = mid - 1;
            else low = mid + 1;
        }

        return numsCopy[low];
    }

private:
    bool canSteal(vector<int>& nums, int k, int capability) {
        if (k == 1) return true;

        int robCnt = 0, n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i] <= capability) {
                robCnt++;
                if (robCnt >= k) return true;
                i++;
            }
        }
        return false;
    }
};