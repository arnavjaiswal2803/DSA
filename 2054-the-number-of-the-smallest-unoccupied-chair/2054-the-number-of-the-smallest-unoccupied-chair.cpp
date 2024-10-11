class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int n = times.size();
        vector<int> indices(n);
        
        for (int i = 0; i < n; i++) indices[i] = i;

        sort(indices.begin(), indices.end(), [&](int a, int b) {
            return times[a][0] < times[b][0];
        });

        priority_queue<int, vector<int>, greater<int>> availableChairs;
        priority_queue<pair<int,int>, vector<pair<int, int>>, 
            greater<pair<int, int>>> occupiedChairs;

        for (int i = 0; i < n; i++) availableChairs.push(i);

        for (int i = 0; i < n; i++) {
            int arrivalTime = times[indices[i]][0];
            int leavingTime = times[indices[i]][1];

            while (!occupiedChairs.empty() && 
                occupiedChairs.top().first <= arrivalTime) {
                    availableChairs.push(occupiedChairs.top().second);
                    occupiedChairs.pop();
                }

            int chairNumber = availableChairs.top();
            if (indices[i] == targetFriend) return chairNumber;
            occupiedChairs.push({leavingTime, chairNumber});
            availableChairs.pop();
        }

        return -1;
    }
};