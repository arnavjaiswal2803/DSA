class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size(), realK = k % n;
        queue<int> q;

        for (int i = 0; i < realK; i++) q.push(nums[n - 1 - i]);
        for (int i = n - 1; i >= 0; i--) {
            if (i - realK >= 0) nums[i] = nums[i - realK];
            else {
                nums[i] = q.front();
                q.pop();
            }
        }
    }
};