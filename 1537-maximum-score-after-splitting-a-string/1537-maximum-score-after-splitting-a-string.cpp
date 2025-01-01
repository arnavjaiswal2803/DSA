class Solution {
public:
    int maxScore(string s) {
        int n = s.size(), maxScore = 0;
        vector<int> leftZeroCnt(n), rightOneCnt(n);

        for (int i = 0; i < n; i++) {
            leftZeroCnt[i] = s[i] == '0' ? 1 : 0;
            rightOneCnt[n - 1 - i] = s[n - 1 - i] == '1' ? 1 : 0;

            if (i > 0) {
                leftZeroCnt[i] += leftZeroCnt[i - 1];
                rightOneCnt[n - 1 - i] += rightOneCnt[n - i];
            }
        }

        for (int i = 1; i < n; i++) {
            maxScore = max(maxScore, leftZeroCnt[i - 1] + rightOneCnt[i]);
        }

        return maxScore;
    }
};