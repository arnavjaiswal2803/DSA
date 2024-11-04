class Solution {
public:
    string compressedString(string word) {
        string comp = "";
        char prevChar = word[0];
        int freq = 1, n = word.length();

        for (int i = 1; i < n; i++) {
            char currChar = word[i];

            if (currChar == prevChar && freq < 9) freq++;
            else {
                comp += (to_string(freq) + prevChar);
                freq = 1;
                prevChar = currChar;
            }
        }
        comp += (to_string(freq) + prevChar);
        
        return comp;
    }
};