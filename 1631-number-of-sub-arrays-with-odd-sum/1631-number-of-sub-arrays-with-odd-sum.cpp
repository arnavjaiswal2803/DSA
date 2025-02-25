class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        const int MOD = 1e9 + 7;
        int n = arr.size();
        int oddCount = 0, evenCount = 1, prefixSum = 0;
        int oddSubarraysCount = 0;

        for (int i = 0; i < n; i++) {
            prefixSum += arr[i];

            if (prefixSum & 1) {
                oddSubarraysCount += evenCount;
                oddCount++;
            } else {
                oddSubarraysCount += oddCount;
                evenCount++;
            }

            oddSubarraysCount %= MOD;
        }

        return oddSubarraysCount;
    }
};