class Solution {
public:
    string removeOccurrences(string s, string part) {
        string ans = s;
        int m = part.size();

        for (int idx = ans.find(part); idx != string::npos; idx = ans.find(part)) {
            ans.erase(idx, m);
        }

        return ans;
    }
};