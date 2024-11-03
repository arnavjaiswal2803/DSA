class Solution {
public:
    bool rotateString(string s, string goal) {
        return goal.length() < s.length() ? false : (s + s).find(goal) != string::npos;
    }
};