class Solution {
    void count(vector<int> &nums, int idx, int n, int bitOr, 
        map<int, int, greater<int> > &freq) {
            if (idx == n) {
                freq[bitOr]++;
                return;
            }

            count(nums, idx + 1, n, bitOr, freq);
            count(nums, idx + 1, n, bitOr | nums[idx], freq);
    }
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int n = nums.size();
        map<int, int, greater<int> > freq;
        count(nums, 0, n, 0, freq);
        return (*freq.begin()).second;
    }
};