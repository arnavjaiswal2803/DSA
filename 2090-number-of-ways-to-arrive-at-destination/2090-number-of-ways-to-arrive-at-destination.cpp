class Solution {
    typedef long long ll;
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> adjList = getAdjacencyList(n, roads);
        return dijkstra(n, adjList);
    }

private:
    int dijkstra(int n, vector<vector<pair<int, int>>>& adjList) {
        const int MOD = 1e9 + 7;

        vector<int> ways(n, 0);
        vector<ll> shortestTime(n, 1e18);
        priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>>
            minHeap;

        ways[0] = 1;
        shortestTime[0] = 0;
        minHeap.push({shortestTime[0], 0});

        while (!minHeap.empty()) {
            ll currTime = minHeap.top().first;
            int node = minHeap.top().second;
            minHeap.pop();

            for (pair<int, int>& it : adjList[node]) {
                int adjNode = it.first, wt = it.second;

                if (currTime + wt < shortestTime[adjNode]) {
                    shortestTime[adjNode] = currTime + wt;
                    minHeap.push({shortestTime[adjNode], adjNode});
                    ways[adjNode] = ways[node];

                } else if (currTime + wt == shortestTime[adjNode]) {
                    ways[adjNode] = (ways[adjNode] + ways[node]) % MOD;
                }
            }
        }

        return ways[n - 1];
    }

    vector<vector<pair<int, int>>>
    getAdjacencyList(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> adjList(n, vector<pair<int, int>>());

        for (vector<int>& road : roads) {
            int u = road[0], v = road[1], wt = road[2];
            adjList[u].push_back({v, wt});
            adjList[v].push_back({u, wt});
        }

        return adjList;
    }
};