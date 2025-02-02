class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        if (n <= 2) return true;

        bool flag1 = false;
        bool flag2 = false;

        for (int i = 1; i < n; i++) {
            if (nums[i] < nums[i - 1]) {
                if (flag1) return false;
                flag1 = true;
            }
        }

        if (flag1 && nums[n - 1] > nums[0]) return false;
        return true;
    }
};