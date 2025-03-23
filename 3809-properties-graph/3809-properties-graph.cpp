class Solution {
public:
    int numberOfComponents(vector<vector<int>>& properties, int k) {
        int n = properties.size();
        
        vector<vector<int>> edges;
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if (intersect(properties[i], properties[j]) >= k) {
                    edges.push_back({i, j});
                }
            }
        }

        vector<vector<int>> adjList = getAdjacencyList(n, edges);
        vector<bool> vis(n, false);
        int connectedComponents = 0;
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                vis[i] = true;
                bfs(i, adjList, vis);
                connectedComponents++;
            }
        }

        return connectedComponents;
    }

private:
    int intersect(vector<int> &a, vector<int> &b) {
        int common = 0;
        vector<bool> present(101);

        for (int &num : a) present[num] = true;
        for (int &num : b) {
            if (present[num]) {
                common++;
                present[num] = false;
            }
        }

        return common;
    }

    vector<vector<int>> getAdjacencyList(int n, vector<vector<int>> &edges) {
        vector<vector<int>> adjList(n, vector<int>());
        for (vector<int> &edge : edges) {
            int u = edge[0], v = edge[1];
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
        return adjList;
    }

    void bfs(int i, vector<vector<int>> &adj, vector<bool> &vis) {
        queue<int> q;
        q.push(i);
        
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                int node = q.front();
                q.pop();
                
                for (int &neighbour : adj[node]) {
                    if (!vis[neighbour]) {
                        vis[neighbour] = true;
                        q.push(neighbour);
                    }
                }
            }
        }
    }
};