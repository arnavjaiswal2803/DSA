class Solution {
    int maxChunks(vector<int>& arr, int n, int startIdx) {
        if (startIdx == n) return 0;

        vector<bool> present(n, false);
        for (int endIdx = startIdx; endIdx < n; endIdx++) {
            present[arr[endIdx]] = true;

            bool areAllPresent = true;
            for (int i = startIdx; i <= endIdx; i++) {
                if (!present[i]) areAllPresent = false;
            }
            if (areAllPresent) return 1 + maxChunks(arr, n, endIdx + 1);
        }
        return -1e8;
    }
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        return maxChunks(arr, n, 0);
    }
};