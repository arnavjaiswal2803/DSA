class Solution {
    bool isPatternFormed(char ch1, char ch2) {
        return (ch1 == 'A' && ch2 == 'B') || (ch1 == 'C' && ch2 == 'D'); 
    }
public:
    int minLength(string s) {
        string dupStr = s;
        int n = s.size(), read = 0, write = 0;
        while (read < n) {
            dupStr[write] = s[read];
            if (write > 0 && isPatternFormed(dupStr[write - 1], dupStr[write]))
                write--;
            else write++;
            read++;
        }
        return write;
    }
};