class Solution {
public:
    bool isCircularSentence(string sentence) {
        int n = sentence.length();
        char firstLetter, lastLetter;
        for (int i = 0; i < n; i++) {
            if (i == 0) firstLetter = sentence[i];
            if (i == n - 1) lastLetter = sentence[i];
            if (sentence[i] == ' ' && sentence[i-1] != sentence[i+1]) return false;
        }
        return firstLetter == lastLetter;
    }
};