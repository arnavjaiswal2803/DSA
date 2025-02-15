typedef long l;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        if (n < 4) return {};
        vector<vector<int>> quads;

        sort (nums.begin(), nums.end());

        for (int a = 0; a < n; a++) {
            if (a > 0 && nums[a] == nums[a - 1]) continue;

            bool bIterated = false;
            for (int b = a + 1; b < n; b++) {
                if (bIterated && nums[b] == nums[b - 1]) continue;

                int c = b + 1, d = n - 1;
                while (c < d) {
                    long sum = (l)nums[a] + (l)nums[b] + (l)nums[c] + (l)nums[d];

                    if (sum < target) c++;
                    else if (sum > target) d--;
                    else {
                        quads.push_back({nums[a], nums[b], nums[c], nums[d]});
                        c++;
                        d--;

                        while (c < d && nums[c] == nums[c - 1]) c++;
                        while (c < d && nums[d] == nums[d + 1]) d--;
                    }
                }

                bIterated = true;
            }
        }

        return quads;
    }
};