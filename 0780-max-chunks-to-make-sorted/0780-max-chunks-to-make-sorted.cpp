class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size(), chunks = 0, maxi = -1;
        for (int i = 0; i < n; i++) {
            maxi = max(maxi, arr[i]);
            if (maxi == i) chunks++;
        }
        return chunks;
    }
};