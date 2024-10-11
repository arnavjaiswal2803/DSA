class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n = nums.size(), maxRamp = 0;

        stack<int> st;
        for (int i = 0; i < n; i++) {
            if (st.empty() || nums[i] < nums[st.top()]) st.push(i);
        }

        for (int i = n - 1; i >= 0 && !st.empty(); i--) {
            while (!st.empty() && nums[i] >= nums[st.top()]) {
                maxRamp = max(maxRamp, i - st.top());
                st.pop();
            }
        }

        return maxRamp;
    }
};