class Solution {
    int getBit(int num, int pos) { return (num & (1 << pos)) != 0; }
public:
    int minimumDifference(vector<int>& nums) {
        int N = nums.size();
        int totalSum = accumulate(nums.begin(), nums.end(), 0);

        int n = N / 2;
        vector<vector<int>> left(n + 1), right(n + 1);

        for (int mask = 0; mask < (1 << n); mask++) {
            int count = 0, leftSum = 0, rightSum = 0;

            for (int idx = 0; idx < n; idx++) {
                if (getBit(mask, idx)) {
                    count++;
                    leftSum += nums[idx];
                    rightSum += nums[idx + n];
                }
            }

            left[count].push_back(leftSum);
            right[count].push_back(rightSum);
        }

        for (int count = 0; count <= n; count++) 
            sort(right[count].begin(), right[count].end());

        int ans = min(abs(totalSum - 2*left[n][0]), abs(totalSum - 2*right[n][0]));
        for (int leftCnt = 1; leftCnt < n; leftCnt++) {
            for (int &a : left[leftCnt]) {
                int rightCnt = n - leftCnt;
                vector<int> &vec = right[rightCnt];
                int b = ((totalSum - 2 * a) / 2);

                auto it = lower_bound(vec.begin(), vec.end(), b);
                if (it != vec.end()) {
                    int sum1 = a + *it;
                    ans = min(ans, abs(totalSum - 2 * sum1));
                }
            }
        }

        return ans;
    }
};