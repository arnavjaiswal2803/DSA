class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        unordered_map<int, int> freq;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                freq[nums[i] * nums[j]]++;
            }
        }

        for (auto &it : freq) {
            if (it.second >= 2) {
                ans += it.second * (it.second - 1) * 4;
            }
        }

        return ans;
    }
};