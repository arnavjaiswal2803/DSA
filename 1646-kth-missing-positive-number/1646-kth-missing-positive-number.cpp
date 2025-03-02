class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size(), low = 0, high = n - 1;
        while (low <= high) {
            int mid = (low + ((high - low) >> 1));

            int missing = arr[mid] - (mid + 1);
            if (missing < k) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return high + 1 + k;    // see striver's video for derivation 
    }
};