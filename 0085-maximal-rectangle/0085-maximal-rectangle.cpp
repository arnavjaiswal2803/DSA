class Solution {
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
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size(), n = matrix[0].size(), maxArea = 0;
        vector<int> currHeight(n, 0);

        for (int row = 0; row < m; row++) {
            for (int col = 0; col < n; col++) {
                currHeight[col] = matrix[row][col] == '0' ? 0 : currHeight[col] + 1;
            }
            maxArea = max(maxArea, largestRectangleArea(currHeight));
        }

        return maxArea;
    }
};