class Solution {
    bool getBit(int num, int pos) { return ((num >> pos) & 1) > 0; }

    int countSetBits(int n) {
        int count = 0;
        for (int i = 0; i <= 31; i++) if (getBit(n, i)) count++;
        return count;
    }
public:
    bool canSortArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> dup(nums);

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < n - i; j++) {
                if (dup[j] > dup[j + 1]) {
                    if (countSetBits(dup[j]) != countSetBits(dup[j + 1])) 
                        return false;
                    swap(dup[j], dup[j + 1]);
                }
            }
        }

        return true;
    }
};