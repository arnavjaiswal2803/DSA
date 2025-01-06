class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size(), rightOne = 0, rightSum = 0, leftOne = 0, leftSum = 0;
        vector<int> ans(n);
        
        for (int i = 0; i < n; i++) {
            rightSum += rightOne;
            if (boxes[i] == '1') rightOne++;
        }

        for (int i = n - 1; i >= 0; i--) {
            leftSum += leftOne;

            ans[i] = rightSum + leftSum;

            if (boxes[i] == '1') {
                leftOne++;
                rightOne--;
            }
            
            rightSum -= rightOne;
        }

        return ans;
    }
};