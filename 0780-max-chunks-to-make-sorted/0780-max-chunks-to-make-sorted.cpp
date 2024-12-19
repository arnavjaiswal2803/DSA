class Solution {
    int maxChunks(vector<int>& arr, int n, int startIdx) {
        if (startIdx == n) return 0;

        vector<bool> present(n, false);
        int absentCount = 0;
        for (int endIdx = startIdx; endIdx < n; endIdx++) {
            if (!present[endIdx]) absentCount++;
            if (arr[endIdx] >= startIdx && arr[endIdx] <= endIdx &&
                !present[arr[endIdx]])
                    absentCount--;
            present[arr[endIdx]] = true;

            if (absentCount == 0)return 1 + maxChunks(arr, n, endIdx + 1);
        }

        return -1e8;
    }

public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        return maxChunks(arr, n, 0);
    }
};