class Solution {
    bool find(int n, unordered_set<string>& hash, string& curr, string& ans) {
        if (curr.size() == n) {
            if (hash.find(curr) == hash.end()) {
                ans = curr;
                return true;
            }
            return false;
        }

        curr += "0";
        if (find(n, hash, curr, ans)) return true;
        curr.pop_back();

        curr += "1";
        if (find(n, hash, curr, ans)) return true;
        curr.pop_back();

        return false;
    }
public:
    string findDifferentBinaryString(vector<string>& nums) {
        unordered_set<string> hash(nums.begin(), nums.end());
        string ans = "", curr = "";
        find(nums.size(), hash, curr, ans);
        return ans;
    }
};