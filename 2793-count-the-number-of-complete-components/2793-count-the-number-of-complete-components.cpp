class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<bool> vis(n, false);
        vector<vector<int>> adjList = getAdjacencyList(n, edges);
        int completeComponents = 0;

        for (int i = 0; i < n; i++) {
            int componentSize = 0;
            if (!vis[i] && dfs(i, adjList, vis, componentSize))
                completeComponents++;
        }

        return completeComponents;
    }

private:
    bool dfs(int node, vector<vector<int>>& adjList, vector<bool>& vis,
             int& compSize) {
        vis[node] = true;
        compSize++;

        bool isComplete = true;
        for (int& adjNode : adjList[node]) {
            if (!vis[adjNode])
                isComplete &= dfs(adjNode, adjList, vis, compSize);
        }

        return isComplete & (adjList[node].size() == compSize - 1);
    }

    vector<vector<int>> getAdjacencyList(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adjList(n, vector<int>());
        
        for (vector<int>& edge : edges) {
            int u = edge[0], v = edge[1];
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
        
        return adjList;
    }
};