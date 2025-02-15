typedef long l;
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        if (n < 4) return {};
        set<vector<int>> quadSet;

        for (int a = 0; a < n; a++) {
            for (int b = a + 1; b < n; b++) {
                unordered_set<int> hash;
                for (int c = b + 1; c < n; c++) {
                    long toFind = (l)target - ((l)nums[a] + (l)nums[b] + (l)nums[c]);
                    if (toFind > INT_MAX || toFind < INT_MIN) continue;

                    if (hash.find(toFind) != hash.end()) {
                        vector<int> quad = {nums[a], nums[b], nums[c], (int)toFind};
                        sort(quad.begin(), quad.end());
                        quadSet.insert(quad);
                    }

                    hash.insert(nums[c]);
                }
            }
        }

        vector<vector<int>> quads(quadSet.begin(), quadSet.end());
        return quads;
    }
};