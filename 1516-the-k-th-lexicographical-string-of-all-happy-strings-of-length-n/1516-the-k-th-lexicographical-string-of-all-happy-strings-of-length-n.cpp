class Solution {
    void generate(int idx, int n, string happyString, vector<string>& happyStrings) {
        if (idx == n) {
            happyStrings.push_back(happyString);
            return;
        }

        for (int i = 0; i < 3; i++) {
            char ch = ('a' + i);
            if (idx == 0 || happyString[idx - 1] != ch) 
                generate(idx + 1, n, happyString + ch, happyStrings);
        }
    }
public:
    string getHappyString(int n, int k) {
        vector<string> happyStrings;
        generate(0, n, "", happyStrings);
        return k <= happyStrings.size() ? happyStrings[k - 1] : "";
    }
};