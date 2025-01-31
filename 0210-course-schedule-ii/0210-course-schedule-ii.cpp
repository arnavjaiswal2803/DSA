class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses, vector<int>());
        vector<int> indeg(numCourses, 0), courseOrder;

        for (vector<int> &prerequisite : prerequisites) {
            int u = prerequisite[0], v = prerequisite[1];
            adj[v].push_back(u);
            indeg[u]++;
        }

        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (indeg[i] == 0) q.push(i);
        }

        int count = 0;
        while (!q.empty()) {
            int node = q.front();
            q.pop();

            count++;
            courseOrder.push_back(node);

            for (int &adjNode : adj[node]) {
                indeg[adjNode]--;
                if (indeg[adjNode] == 0) q.push(adjNode);
            }
        }

        return count == numCourses ? courseOrder : vector<int>{};
    }
};