class Solution {
    void dfs(int node, int parent, vector<vector<int>>& adj, vector<int>& time,
             vector<int>& minTime, vector<vector<int>>& bridges,
             vector<bool>& vis, int& step) {
        vis[node] = true;

        step++;
        time[node] = step;
        minTime[node] = step;

        for (auto& adjNode : adj[node]) {
            if (adjNode != parent) {
                if (!vis[adjNode]) {
                    dfs(adjNode, node, adj, time, minTime, bridges, vis, step);
                }
                minTime[node] = min(minTime[node], minTime[adjNode]);
                if (minTime[adjNode] > time[node])
                    bridges.push_back({node, adjNode});
            }
        }
    }

    vector<vector<int>> getAdjacencyList(int n,
                                         vector<vector<int>>& connections) {
        vector<vector<int>> adj(n, vector<int>());
        int connectionsCount = connections.size();
        for (int i = 0; i < connectionsCount; i++) {
            int u = connections[i][0], v = connections[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        return adj;
    }

public:
    vector<vector<int>> criticalConnections(int n,
                                            vector<vector<int>>& connections) {
        vector<bool> vis(n, false);
        vector<int> time(n), minTime(n);
        vector<vector<int>> bridges;
        int step = 0;

        vector<vector<int>> adj = getAdjacencyList(n, connections);
            dfs(0, 0, adj, time, minTime, bridges, vis, step);

        return bridges;
    }
};