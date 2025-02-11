class Solution {
public:
    string removeOccurrences(string s, string part) {
        string ans = s;
        int idx = ans.find(part), m = part.size();

        while (idx != string::npos) {
            ans.erase(idx, m);
            idx = ans.find(part);
        }

        return ans;
    }
};