class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size(), maxValidity = days[n - 1] + 30;
        vector<int> next(maxValidity + 1, 0);

        for (int idx = n - 1; idx >= 0; --idx) {
            vector<int> curr(maxValidity + 1, 0);
            for (int validUpto = maxValidity; validUpto >= 0; --validUpto) {
                if (days[idx] <= validUpto) 
                    curr[validUpto] = next[validUpto];
                else {
                    curr[validUpto] = min({
                        costs[0] + next[days[idx]], 
                        costs[1] + next[days[idx] + 6], 
                        costs[2] + next[days[idx] + 29]
                    });
                }
            }
            next = curr;
        }

        return next[0];
    }
}; 