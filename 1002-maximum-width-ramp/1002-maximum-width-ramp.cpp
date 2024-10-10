class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n = nums.size();

        vector<int> indices(n);
        for (int i = 0; i < n; i++) indices[i] = i;

        sort(indices.begin(), indices.end(), [&](int i, int j) {
            return nums[i] != nums[j] ? nums[i] < nums[j] : i < j;
        });

        int minIdx = indices[0], maxRamp = 0;
        for (int i = 1; i < n; i++) {
            maxRamp = max(maxRamp, indices[i] - minIdx);
            minIdx = min(minIdx, indices[i]);
        }

        return maxRamp;
    }
};