class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size(), cnt1 = 0, cnt2 = 0;
        long el1 = LONG_MIN, el2 = LONG_MIN;
        vector<int> ans;

        for (int &num : nums) {
            if (cnt1 == 0 && num != el2) {
                cnt1 = 1;
                el1 = num;
            } else if (cnt2 == 0 && num != el1) {
                cnt2 = 1;
                el2 = num;
            } else if (num == el1) cnt1++;
            else if (num == el2) cnt2++;
            else {
                cnt1--;
                cnt2--;
            }
        }

        int cnt11 = 0, cnt21 = 0;
        for (int &num : nums) {
            if (num == el1) cnt11++;
            else if (num == el2) cnt21++;
        }
        if (cnt11 > n / 3) ans.push_back(el1);
        if (cnt21 > n / 3) ans.push_back(el2);

        return ans;
    }
};