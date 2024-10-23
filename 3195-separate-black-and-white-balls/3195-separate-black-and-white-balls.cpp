class Solution {
public:
    long long minimumSteps(string s) {
        int n = s.length(), onesCount = 0;
        long long ans = 0;

        for (int i = 0; i < n; i++) {
            if (s[i] == '1') onesCount++;
            else ans += (long long) onesCount;
        }
        
        return ans;
    }
};