class Solution {
    typedef pair<int, pair<int, int>> pi;
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int k = nums.size(), rangeStart = 0, rangeEnd = INT_MAX, maxVal = INT_MIN;
        priority_queue<pi, vector<pi>, greater<pi>> pq;

        for (int i = 0; i < k; i++) {
            pq.push({nums[i][0], {i, 0}});
            maxVal = max(maxVal, nums[i][0]);
        }

        while (pq.size() == k) {
            pi elem = pq.top();
            pq.pop();

            int smallestVal = elem.first;
            int row = elem.second.first, col = elem.second.second;

            if (maxVal - smallestVal < rangeEnd - rangeStart) {
                rangeStart = smallestVal;
                rangeEnd = maxVal;
            }

            if (col + 1 < nums[row].size()) {
                int newVal = nums[row][col + 1];
                pq.push({newVal, {row, col + 1}});
                maxVal = max(maxVal, newVal);
            }
        }

        return {rangeStart, rangeEnd};
    }
};