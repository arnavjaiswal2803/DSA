class Solution {
public:
    int maxScore(string s) {
        int n = s.size(), maxScore = 0, leftZeroCnt = 0, rightOneCnt = 0;

        for (int i = n - 1; i >= 1; i--) rightOneCnt += s[i] == '1';
        for (int i = 1; i < n; i++) {
            leftZeroCnt += s[i - 1] == '0';
            maxScore = max(maxScore, leftZeroCnt + rightOneCnt);
            rightOneCnt -= s[i] == '1';
        }

        return maxScore;
    }
};