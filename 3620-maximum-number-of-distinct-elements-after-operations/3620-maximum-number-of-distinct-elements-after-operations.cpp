class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        // idea is to replace each nums[i] with its lowest possible value within range

        int n = nums.size(), distinctCount = 0;

        // lastAlloted is the number that the previous nums[i] was replaced with
        long long lastAlloted = INT_MIN; 

        sort (nums.begin(), nums.end());

        for (int i = 0; i < n; ++i) {
            long long minRange = nums[i] - k, maxRange = nums[i] + k;

            if (lastAlloted < minRange) {
                // curr element's lowest possible value can be used.
                lastAlloted = minRange;
                distinctCount++;
            } else if (lastAlloted < maxRange) {
                // a value less than or equal to curr element's max val can be used
                lastAlloted = lastAlloted + 1;
                distinctCount++;
            }
        }

        return distinctCount;
    }
};