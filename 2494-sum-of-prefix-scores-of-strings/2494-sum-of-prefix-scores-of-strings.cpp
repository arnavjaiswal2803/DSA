class TrieNode {
    bool flag = false;
    int prefixCount = 0;
    TrieNode* links[26];
public:
    bool containsKey(char ch) {
        return links[ch - 'a'] != NULL;
    }

    void put(char ch, TrieNode* node) {
        links[ch - 'a'] = node;
    }

    TrieNode* get(char ch) {
        return links[ch - 'a'];
    }

    void setEnd() {
        flag = true;
    }

    void incrementPrefixCount() {
        prefixCount++;
    }

    int getPrefixCount() {
        return prefixCount;
    }
};

class Trie {
    TrieNode* root;
public:
    Trie() {
        root = new TrieNode();
    }

    void insert(string word) {
        TrieNode* temp = root;
        int n = word.length();
        for (int i = 0; i < n; i++) {
            if (!temp->containsKey(word[i])) temp->put(word[i], new TrieNode());
            temp = temp->get(word[i]);
            temp->incrementPrefixCount();
        }
        temp->setEnd();
    }

    int getAllPrefixesCountSum(string word) {
        TrieNode* temp = root;
        int n = word.length(), scoreSum = 0;
        for (int i = 0; i < n; i++) {
            temp = temp->get(word[i]);
            scoreSum += temp->getPrefixCount();
        }
        return scoreSum;
    }
};

class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        vector<int> ans;
        Trie* trie = new Trie();
        for (auto word : words) trie->insert(word);
        for (auto word : words) ans.push_back(trie->getAllPrefixesCountSum(word));
        return ans;
    }
};