class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size(), rightOne = 0, rightSum = 0, leftOne = 0, leftSum = 0;
        vector<int> ans(n, 0);
        
        for (int i = 0; i < n; i++) {
            rightSum += rightOne;
            ans[i] += rightSum;
            if (boxes[i] == '1') rightOne++;

            leftSum += leftOne;
            ans[n - 1 - i] += leftSum;
            if (boxes[n - 1 - i] == '1') leftOne++;
        }

        return ans;
    }
};