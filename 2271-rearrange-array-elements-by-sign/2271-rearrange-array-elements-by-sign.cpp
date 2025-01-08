class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size(), i = 0, j = 0;
        vector<int> pos, neg, ans;

        for (int &num : nums) num >= 0 ? pos.push_back(num) : neg.push_back(num);
        while (i + j < n) {
            ans.push_back(pos[i++]);
            ans.push_back(neg[j++]);
        };

        return ans;
    }
};