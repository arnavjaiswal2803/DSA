class Solution {
public:
    int minLength(string s) {
        int ABIdx = s.find("AB"), CDIdx = s.find("CD");
        while (ABIdx != string::npos || CDIdx != string::npos) {
            if (ABIdx != string::npos) {
                s = s.substr(0, ABIdx) + s.substr(ABIdx + 2);
            }

            CDIdx = s.find("CD");
            if (CDIdx != string::npos) {
                s = s.substr(0, CDIdx) + s.substr(CDIdx + 2);
            }

            ABIdx = s.find("AB"); 
            CDIdx = s.find("CD");
        }
        return s.size();
    }
};