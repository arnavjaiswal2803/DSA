class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        vector<int> arr(1e6 + 2, 0);
        for (auto &in : intervals) {
            arr[in[0]]++;
            arr[in[1] + 1]--;
        }
        int sum = 0, maxSum = 1;
        for (auto i : arr) {
            sum += i;
            maxSum = max(maxSum, sum);
        }
        return maxSum;
    }
};