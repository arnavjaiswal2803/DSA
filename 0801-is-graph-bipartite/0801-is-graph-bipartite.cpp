class Solution {
    bool dfs(int node, vector<vector<int>>& graph, vector<int>& color, int currColor) {
        color[node] = currColor;

        for (int adjNode : graph[node]) {
            if (color[adjNode] == -1) {
                if (!dfs(adjNode, graph, color, 1 - currColor)) return false;
            } else if (color[adjNode] == currColor) return false;
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);

        for (int i = 0; i < n; i++) {
            if (color[i] == -1)
                if (!dfs(i, graph, color, 0)) return false;
        }
        return true;
    }
};