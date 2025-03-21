class Solution {
public:
    vector<int> minimumCost(int n, vector<vector<int>>& edges,
                            vector<vector<int>>& query) {
        DisjointSet ds(n);

        for (vector<int> &edge : edges) {
            int u = edge[0], v = edge[1];
            ds.unionByRank(u, v);
        }

        unordered_map<int, int> componentMinCost;
        for (vector<int> &edge : edges) {
            int u = edge[0], wt = edge[2];
            int ultiPar = ds.findUltimateParent(u);

            if (componentMinCost.find(ultiPar) == componentMinCost.end()) {
                componentMinCost[ultiPar] = wt;
            } else {
                componentMinCost[ultiPar] &= wt;
            }
        }

        int k = query.size();
        vector<int> ans(k);
        for (int i = 0; i < k; i++) {
            int s = query[i][0], t = query[i][1];
            int ultiParS = ds.findUltimateParent(s), 
                ultiParT = ds.findUltimateParent(t);

            ans[i] = ultiParS == ultiParT ? componentMinCost[ultiParS] : -1;
        }

        return ans;
    }

private:
    class DisjointSet {
        vector<int> parent;
        vector<long long> rank;

    public:
        DisjointSet(int n) {
            rank.resize(n + 1, 1);
            parent.resize(n + 1);
            for (int i = 0; i <= n; i++) parent[i] = i;
        }

        int findUltimateParent(int u) {
            if (parent[u] == u) return u;
            return parent[u] = findUltimateParent(parent[u]); 
        }

        void unionByRank(int u, int v) {
            int ultiParU = findUltimateParent(u);
            int ultiParV = findUltimateParent(v);

            if (rank[ultiParU] < rank[ultiParV]) {
                parent[ultiParU] = ultiParV;
            } else if (rank[ultiParU] > rank[ultiParV]) {
                parent[ultiParV] = ultiParU;
            } else {
                parent[ultiParV] = ultiParU;
                rank[ultiParV]++;
            }
        }
    };
};