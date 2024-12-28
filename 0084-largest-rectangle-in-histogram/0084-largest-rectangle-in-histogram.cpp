class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size(), maxArea = 0;
        stack<int> st;

        for (int idx = 0; idx <= n; idx++) {
            while (!st.empty() && (idx == n || heights[st.top()] >= heights[idx])) {
                int height = heights[st.top()];
                st.pop();
                int width = st.empty() ? idx : idx - st.top() - 1;
                maxArea = max(maxArea, height * width);
            }
            st.push(idx);
        }

        return maxArea;
    }
};