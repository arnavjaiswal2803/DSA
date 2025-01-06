class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        vector<int> ans(n), movingRightPrefixSum(n), movingLeftPrefixSum(n);
        
        int oneCount = 0;
        for (int i = 0; i < n; i++) {
            movingRightPrefixSum[i] = oneCount;
            if (i > 0) movingRightPrefixSum[i] += movingRightPrefixSum[i - 1];
            if (boxes[i] == '1') oneCount++;
        }

        oneCount = 0;
        for (int i = n - 1; i >= 0; i--) {
            movingLeftPrefixSum[i] = oneCount;
            if (i < n - 1) movingLeftPrefixSum[i] += movingLeftPrefixSum[i + 1];
            if (boxes[i] == '1') oneCount++;

            ans[i] = movingRightPrefixSum[i] + movingLeftPrefixSum[i];
        }

        return ans;
    }
};