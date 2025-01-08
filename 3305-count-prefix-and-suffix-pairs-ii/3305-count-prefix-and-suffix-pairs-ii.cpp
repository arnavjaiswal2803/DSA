class TrieNode {
    unordered_map<string, TrieNode*> links;
    int freq = 0;

public:

    TrieNode() {
    }

    bool containsKey(string key) {
        return links.find(key) != links.end();
    }

    void put(string key, TrieNode* node) {
        links[key] = node;
    }

    TrieNode* get(string key) {
        return links[key];
    }

    void incrementFrequency() {
        freq++;
    }

    int getFrequency() {
        return freq;
    }
};

class Trie {
    TrieNode* root;

public: 

    Trie() {
        root = new TrieNode();
    }

    long long insertAndCountPrefixesAndSuffixes(string& word) {
        int n = word.size();
        long long count = 0;
        TrieNode* node = root;
        for (int i = 0; i < n; i++) {
            string key = "";
            key += word[i];
            key += word[n - 1 - i];
            
            if (!node->containsKey(key)) {
                node->put(key, new TrieNode());
            }
            node = node->get(key);
            count += node->getFrequency();
        }
        node->incrementFrequency();
        return count;
    }
};

class Solution {
public:
    long long countPrefixSuffixPairs(vector<string>& words) {
        int n = words.size();
        long long count = 0;
        Trie* trie = new Trie();
        for (int i = 0; i < n; i++) 
            count += trie->insertAndCountPrefixesAndSuffixes(words[i]);
        return count;
    }
};