class DisjointSet {
    vector<int> size, parent;
public:
    DisjointSet(int n) {
        size.resize(n + 1, 1);
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++) parent[i] = i;
    }

    int findParent(int i) {
        if (parent[i] == i) return i;
        return parent[i] = findParent(parent[i]);
    }

    void createUnion(int u, int v) {
        int ultimateParentU = findParent(u);
        int ultimateParentV = findParent(v);

        if (ultimateParentU == ultimateParentV) return;

        if (ultimateParentU <= ultimateParentV) {
            parent[ultimateParentU] = ultimateParentV;
            size[ultimateParentV] += size[ultimateParentU];
        } else {
            parent[ultimateParentV] = ultimateParentU;
            size[ultimateParentU] += size[ultimateParentV];
        }
    }
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        DisjointSet ds(n);
        unordered_map<int, int> rowMap, colMap;

        for (int i = 0; i < n; i++) {
            int row = stones[i][0], col = stones[i][1];

            if (rowMap.find(row) == rowMap.end()) rowMap[row] = i; 
            else ds.createUnion(rowMap[row], i);

            if (colMap.find(col) == colMap.end()) colMap[col] = i;
            else ds.createUnion(colMap[col], i);
        }

        int cannotRemove = 0;
        for (int i = 0; i < n; i++) if (ds.findParent(i) == i) cannotRemove++;

        return n - cannotRemove;
    }
};