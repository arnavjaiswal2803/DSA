class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();

        int smallerCnt = 0, equalCnt = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] < pivot) smallerCnt++;
            else if (nums[i] == pivot) equalCnt++;
        }

        vector<int> ans(n);
        int nextSmallerIdx = 0, nextEqualIdx = smallerCnt;
        int nextGreaterIdx = smallerCnt + equalCnt;
        for (int i = 0; i < n; i++) {
            if (nums[i] < pivot) ans[nextSmallerIdx++] = nums[i];
            else if (nums[i] == pivot) ans[nextEqualIdx++] = nums[i];
            else ans[nextGreaterIdx++] = nums[i];
        }

        return ans;
    }
};