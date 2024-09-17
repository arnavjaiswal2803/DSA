class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size(), currIdx = 0, moves = 0;
        while (currIdx < n - 1) {
            if (currIdx + nums[currIdx] >= n - 1) return ++moves;
            
            int maxRange = -1, maxIdx = -1;
            for (int nextIdx = currIdx + 1; 
                nextIdx < n && nextIdx <= currIdx + nums[currIdx]; nextIdx++) {
                if (nextIdx + nums[nextIdx] > maxRange) {
                    maxRange = nextIdx + nums[nextIdx];
                    maxIdx = nextIdx;
                }
            }
            currIdx = maxIdx;
            moves++;
        } 
       return moves;
    }
};