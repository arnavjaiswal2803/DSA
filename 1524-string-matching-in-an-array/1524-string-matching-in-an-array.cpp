class TrieNode {
    TrieNode* links[26] = {0};
    int frequency;

    public: 

    TrieNode() {
        frequency = 0;
    }

    bool containsKey(char ch) {
        return links[ch - 'a'];
    }

    void put(char ch, TrieNode* trieNode) {
        links[ch - 'a'] = trieNode;
    }

    TrieNode* get(char ch) {
        return links[ch - 'a'];
    }

    void incrementFrequency() {
        frequency++;
    }

    int getFrequency() {
        return frequency;
    }
};

class Trie {
    TrieNode* root;

    public:

    Trie() {
        root = new TrieNode();
    }

    void insertSuffixesOfWord(string& word) {
        int n = word.size();
        for (int i = 0; i < n; i++) {
            TrieNode* node = root;

            for (int j = i; j < n; j++) {
                if (!node->containsKey(word[j])) node->put(word[j], new TrieNode());
                node = node->get(word[j]);
                node->incrementFrequency();
            }
        }
    }

    bool isSubstring(string& word) {
        int n = word.size();
        TrieNode* node = root;
        for (int i = 0; i < n; i++) {
            node = node->get(word[i]);
        }
        return node->getFrequency() > 1;
    }
};

class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        int n = words.size();
        Trie* trie = new Trie();
        vector<string> ans;

        for (string& word : words) trie->insertSuffixesOfWord(word);
        for (string& word : words) if (trie->isSubstring(word)) ans.push_back(word);

        return ans;
    }
};