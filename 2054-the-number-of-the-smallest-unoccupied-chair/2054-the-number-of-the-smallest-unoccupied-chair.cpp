class Solution {
    int getChairNumber(vector<int> &chairs, vector<int> &time) {
        int n = chairs.size();
        for (int i = 0; i < n; i++) {
            int leavingTime = chairs[i];
            if (leavingTime <= time[0]) {
                chairs[i] = time[1];
                return i;
            }
        }
        return -1;
    }
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int n = times.size();
        vector<int> chairs(n, -1), indices(n);

        for (int i = 0; i < n; i++) indices[i] = i;

        sort(indices.begin(), indices.end(), [&](int a, int b) {
            return times[a][0] < times[b][0];
        });

        for (int i = 0; i < n; i++) {
            int chairNumber = getChairNumber(chairs, times[indices[i]]);
            if (indices[i] == targetFriend) return chairNumber;
        }

        return -1;
    }
};