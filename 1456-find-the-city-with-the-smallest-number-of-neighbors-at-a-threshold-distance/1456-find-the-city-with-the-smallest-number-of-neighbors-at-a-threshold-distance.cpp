class Solution {
    const int INF = 1e9;

    vector<vector<int>> getAdjacencyMatrix(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adjMat(n, vector<int>(n, INF));

        int e = edges.size();
        for (int i = 0; i < e; i++) {
            int u = edges[i][0], v = edges[i][1], wt = edges[i][2];
            adjMat[u][v] = wt;
            adjMat[v][u] = wt;
        }

        for (int i = 0; i < n; i++) adjMat[i][i] = 0;

        return adjMat;
    }

    void floydWarshal(int n, vector<vector<int>>& adjMat) {
        for (int via = 0; via < n; via++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    adjMat[i][j] = min(adjMat[i][j], adjMat[i][via] + adjMat[via][j]);
                }
            }
        }
    }
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> adjMat = getAdjacencyMatrix(n, edges);
        
        floydWarshal(n, adjMat);

        int ans = -1, minCityCount = INT_MAX;
        for (int i = 0; i < n; i++) {
            int cityCount = 0;
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                if (adjMat[i][j] <= distanceThreshold) cityCount++;
            }

            if (cityCount <= minCityCount) {
                minCityCount = cityCount;
                ans = i;
            }
        }

        return ans;
    }
};