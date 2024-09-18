class Solution {
    static bool comp(string &s1, string &s2) {
        if (s1 + s2 > s2 + s1) return true;
        return false;
    }
public:
    string largestNumber(vector<int>& nums) {
        int n = nums.size();
        string ans = "";
        vector<string> numStr;
        for (auto &i : nums) numStr.push_back(to_string(i));
        sort(numStr.begin(), numStr.end(), comp);
        for (int i = 0; i < n; i++) {
            if (numStr[0] == "0") return "0";
            ans += numStr[i];
        }
        return ans;
    }
};