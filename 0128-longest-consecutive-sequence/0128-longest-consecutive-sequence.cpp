class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size(), maxLen = 0;
        unordered_set<long> st;

        for (int i = 0; i < n; i++) st.insert(nums[i]);

        for (auto num : st) {
            int currLen = 1;
            if (st.find((long)num - 1) == st.end()) {
                num++;
                while (st.find(num) != st.end()) {
                    currLen++;
                    num++;
                }
            }
            maxLen = max(maxLen, currLen);
        }

        return maxLen;
    }
};