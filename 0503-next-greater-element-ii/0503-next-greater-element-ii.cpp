class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        const int OUT_OF_RANGE_NUM = -1e9 - 1;
        int n = nums.size();
        vector<int> nge(n, OUT_OF_RANGE_NUM);
        stack<int> st;
        for (int i = 2 * n - 1; i >= 0; i--) {
            if (i < n && nge[i] != OUT_OF_RANGE_NUM) continue;
            while (!st.empty() && nums[i % n] >= st.top()) st.pop();
            if (!st.empty()) nge[i % n] = st.top();
            st.push(nums[i % n]);
        }
        for (int i = 0; i < n; i++) {
            if (nge[i] == OUT_OF_RANGE_NUM) nge[i] = -1;
        }
        return nge;
    }
};