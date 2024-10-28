class Solution {
    class TrieNode {
        unordered_map<string, TrieNode*> links;
        bool flag = false;
    public:
        void put(string &key, TrieNode* node) {
            links[key] = node;
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

        void insert(string &path) {
            TrieNode* node = root;
            int n = path.length();

            for (int i = 1; i < n; i++) {
                string folderName = "";
                while (i < n && path[i] != '/') folderName += path[i++];

                if (node->get(folderName) == NULL)
                    node->put(folderName, new TrieNode());
                node = node->get(folderName);
            }
            node->setEnd();
        }
        
        bool hasPrefixes(string &path) {
            TrieNode* node = root;
            int n = path.length();

            for (int i = 1; i < n; i++) {
                string folderName = "";
                while (i < n && path[i] != '/') folderName += path[i++];

                if (node->get(folderName)->isEnd() && i != n) return true;
                node = node->get(folderName);
            }

            return false;
        }
    };
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        Trie *trie = new Trie();
        vector<string> ans;
        int n = folder.size();

        for (int i = 0; i < n; i++) trie->insert(folder[i]);
        for (int i = 0; i < n; i++) 
            if (!(trie->hasPrefixes(folder[i]))) ans.push_back(folder[i]);

        return ans;
    }
};