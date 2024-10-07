class Solution {
    deque<string> getWords(string str) {
        int n = str.size();
        deque<string> words;
        string word = "";
        for (int i = 0; i < n; i++) {
            if (str[i] != ' ') word += str[i];
            else {
                words.push_back(word);
                word = "";
            }
        }
        words.push_back(word);
        return words;
    }
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
        deque<string> s1 = getWords(sentence1), s2 = getWords(sentence2);
        while (!s1.empty() && !s2.empty() && s1.front() == s2.front()) {
            s1.pop_front();
            s2.pop_front();
        }
        while (!s1.empty() && !s2.empty() && s1.back() == s2.back()) {
            s1.pop_back();
            s2.pop_back();
        }
        return s1.empty() || s2.empty();
    }
};