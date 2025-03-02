class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size(), missingNum = k;
        for (int i = 0; i < n; i++) {
            if (arr[i] <= missingNum) missingNum++;
            else break;
        }

        return missingNum;
    }
};