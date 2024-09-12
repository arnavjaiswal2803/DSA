class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> maximums;
        multiset<int, greater<int>> window;

        for (int i = 0; i < k; i++) window.insert(nums[i]);
        maximums.push_back(*window.begin());

        for (int i = k; i < n; i++) {
            window.erase(window.find(nums[i - k]));
            window.insert(nums[i]);
            maximums.push_back(*window.begin());
        }
        
        return maximums;
    }
};