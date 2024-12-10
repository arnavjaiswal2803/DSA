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

        if (size[ultimateParentU] <= size[ultimateParentV]) {
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
    int makeConnected(int n, vector<vector<int>>& connections) {
        DisjointSet ds(n);

        int freeEdges = 0;
        for (auto &connection : connections) {
            int u = connection[0], v = connection[1];

            if (ds.findParent(u) == ds.findParent(v)) {
                freeEdges++;
                continue;
            }
            ds.createUnion(u, v);
        }

        int reqEdges = 0;
        for (int i = 0; i < n; i++) if (ds.findParent(i) == i) reqEdges++;
        reqEdges--;

        return reqEdges <= freeEdges ? reqEdges : -1;
    }
};