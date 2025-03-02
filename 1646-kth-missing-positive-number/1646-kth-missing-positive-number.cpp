class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        vector<bool> hash(2001, false);

        for (int i = 0; i < n; i++) {
            hash[arr[i]] = true;
        }

        int counter = 0;
        for (int i = 1; i <= 2000; i++) {
            if (!hash[i]) {
                counter++;
                if (counter == k) {
                    return i;
                }
            }
        }

        return -1;
    }
};