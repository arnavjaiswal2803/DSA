class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size(), chunks = 0;

        for (int startIdx = 0; startIdx < n; startIdx++) {
            vector<bool> present(n, false);
            int absentCount = 0;
            
            for (int endIdx = startIdx; endIdx < n; endIdx++) {
                if (!present[endIdx]) absentCount++;
                if (arr[endIdx] >= startIdx && arr[endIdx] <= endIdx &&
                    !present[arr[endIdx]])
                        absentCount--;
                present[arr[endIdx]] = true;

                if (absentCount == 0) {
                    chunks++;
                    startIdx = endIdx;
                    break;
                }
            }
        }

        return chunks;
    }
};