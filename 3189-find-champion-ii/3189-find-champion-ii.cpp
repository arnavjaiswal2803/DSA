class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int> inDegree(n, 0);
        for (auto &edge : edges) inDegree[edge[1]]++;

        int champ = 0, minInDegree = inDegree[champ], minInDegreeFreq = 1;
        for (int i = 1; i < n; i++) {
            if (inDegree[i] < minInDegree) {
                champ = i;
                minInDegree = inDegree[champ];
                minInDegreeFreq = 1;
            } else if (inDegree[i] == minInDegree) minInDegreeFreq++;
        }

        return minInDegreeFreq == 1 ? champ : -1;
    }
};