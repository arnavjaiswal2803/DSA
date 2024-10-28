class Solution {
    class TrieNode {
        unordered_map<string, TrieNode*> links;
        bool flag = false;
    public:
        void put(string &s, TrieNode* node) {
            links[s] = node;
        }

        TrieNode* get(string &s) {
            return links[s];
        }

        void setEnd() {
            flag = true;
        }

        bool isEnd() {
            return flag == true;
        }
    };

    class Trie {
        TrieNode* root;
    public: 
        Trie() {
            root = new TrieNode();
        }

        bool canInsert(string &word) {
            TrieNode* node = root;
            int n = word.length();

            for (int i = 1; i < n; i++) {
                string folderName = "";
                while (i < n && word[i] != '/') folderName += word[i++];

                if (node->get(folderName) == NULL) {
                    node->put(folderName, new TrieNode());
                } else if (node->get(folderName)->isEnd()) return false;
                
                node = node->get(folderName);
            }
            node->setEnd();

            return true;
        }
    };
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort (folder.begin(), folder.end(), [&](string &s1, string &s2) {
            return s1.length() < s2.length();
        });

        Trie *trie = new Trie();
        vector<string> ans;
        int n = folder.size();

        for (int i = 0; i < n; i++) {
            if (trie->canInsert(folder[i])) ans.push_back(folder[i]);
        }

        return ans;
    }
};