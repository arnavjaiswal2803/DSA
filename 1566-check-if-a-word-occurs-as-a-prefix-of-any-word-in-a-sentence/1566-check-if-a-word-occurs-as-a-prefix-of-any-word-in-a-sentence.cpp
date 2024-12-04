class Solution {
    class TrieNode {
        TrieNode* list[26];
        bool flag = false;
        int wordIdx = -1;

    public:
        TrieNode* getKey(char ch) { return list[ch - 'a']; }

        void put(char ch, TrieNode* newNode) { list[ch - 'a'] = newNode; }

        void setEnd() { flag = true; }

        bool isEnd() { return flag; }

        void setWordIdx(int idx) {
            if (wordIdx == -1)
                wordIdx = idx;
        }

        int getWordIdx() { return wordIdx; }
    };

    class Trie {
        TrieNode* root;

    public:
        Trie() { root = new TrieNode(); }

        void insertWord(string& word, int wordIdx) {
            int n = word.length();
            TrieNode* node = root;

            for (int i = 0; i < n; i++) {
                if (node->getKey(word[i]) == NULL) {
                    node->put(word[i], new TrieNode());
                    node->setWordIdx(wordIdx);
                }
                node = node->getKey(word[i]);
            }
            node->setEnd();
            node->setWordIdx(wordIdx);
        }

        int getPrefixWordIdx(string& word) {
            int n = word.length();
            TrieNode* node = root;
            for (int i = 0; i < n; i++) {
                if (node->getKey(word[i]) == NULL)
                    return -1;
                node = node->getKey(word[i]);
            }
            return node->getWordIdx();
        }
    };

public:
    int isPrefixOfWord(string sentence, string searchWord) {
        int n = sentence.length(), wordIdx = 1;
        Trie* trie = new Trie();
        string word = "";

        for (int i = 0; i < n; i++) {
            if (sentence[i] == ' ') {
                trie->insertWord(word, wordIdx);
                word = "";
                wordIdx++;
            } else
                word += sentence[i];
        }
        trie->insertWord(word, wordIdx);

        return trie->getPrefixWordIdx(searchWord);
    }
};