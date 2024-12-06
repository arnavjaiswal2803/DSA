class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        int count = 0;
        long long sum = 0;
        unordered_set<int> bannedNumbers;
        
        for (int &i : banned) bannedNumbers.insert(i);
        for (int i = 1; i <= n; i++) {
            if (bannedNumbers.count(i) == 1) continue;
            if (sum + (long long)i > (long long)maxSum) break;
            sum += i;
            count++;
        }

        return count;
    }
};