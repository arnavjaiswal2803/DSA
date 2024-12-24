class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size(), maxLen = 1, maxLenIdx = 0;
        vector<int> dp(n, 1), backtrack(n);

        sort(nums.begin(), nums.end());
        for (int idx = 0; idx < n; idx++) {
            backtrack[idx] = idx;
            for (int prevIdx = 0; prevIdx < idx; prevIdx++) {
                if (nums[idx] % nums[prevIdx] == 0 && 1 + dp[prevIdx] > dp[idx]) {
                    dp[idx] = 1 + dp[prevIdx];
                    backtrack[idx] = prevIdx;

                    if (dp[idx] > maxLen) {
                        maxLen = dp[idx];
                        maxLenIdx = idx;
                    }
                }
            }
        }

        vector<int> answer;
        answer.push_back(nums[maxLenIdx]);
        int i = maxLenIdx;
        while (backtrack[i] != i) {
            answer.push_back(nums[backtrack[i]]);
            i = backtrack[i];
        }

        return answer;
    }
};