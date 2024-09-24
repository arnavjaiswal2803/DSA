class Node {
    bool flag = false;
    Node* links[10];

public:
    bool containsKey(char ch) {
        return links[ch - '0'] != NULL;
    }

    void put(char ch, Node* node) {
        links[ch - '0'] = node;
    }

    Node* get(char ch) {
        return links[ch - '0'];
    }

    void setEnd() {
        flag = true;
    }
};

class Trie {
    Node* root;

public:
    Trie() {
        root = new Node();
    }

    void insert(string num) {
        Node* temp = root;
        int n = num.length();
        for (int i = 0; i < n; i++) {
            if (!temp->containsKey(num[i])) {
                temp->put(num[i], new Node());
            }
            temp = temp->get(num[i]);
        }
        temp->setEnd();
    }

    int calculatePrefix(string num) {
        Node *temp = root;
        int n = num.length(), count = 0;
        for (int i = 0; i < n; i++) {
            if (!temp->containsKey(num[i])) break;
            count++;
            temp = temp->get(num[i]);
        }
        return count;
    }
};

class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        int n = arr1.size(), m = arr2.size(), maxCount = 0;

        Trie* trie = new Trie();
        for (int i = 0; i < n; i++) trie->insert(to_string(arr1[i]));
        for (int i = 0; i < m; i++) 
            maxCount = max(maxCount, trie->calculatePrefix(to_string(arr2[i])));

        return maxCount;
    }
};