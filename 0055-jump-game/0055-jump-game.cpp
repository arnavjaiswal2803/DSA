class Solution {
public:
    bool canJump(vector<int>& nums) {
       int n = nums.size(), currIdx = 0;
       while (currIdx < n) {
        if (currIdx == n - 1) return true;
        if (nums[currIdx] == 0) return false;

        int maxRange = -1, maxIdx = -1;
        for (int nextIdx = currIdx + 1; 
            nextIdx < n && nextIdx <= currIdx + nums[currIdx]; nextIdx++) {
            if (nextIdx + nums[nextIdx] > maxRange) {
                maxRange = nextIdx + nums[nextIdx];
                maxIdx = nextIdx;
            }
        }
        currIdx = maxIdx;
       } 
       return true;
    }
};