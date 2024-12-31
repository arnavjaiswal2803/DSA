class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size(), lastDay = days[n - 1];
        vector<int> cost(lastDay + 1);
        cost[0] = 0;

        int travelIdx = 0;
        for (int currDay = 1; currDay <= lastDay; currDay++) {
            if (currDay < days[travelIdx]) cost[currDay] = cost[currDay - 1];
            else {
                cost[currDay] = min({
                    cost[currDay - 1] + costs[0], 
                    cost[max(0, currDay - 7)] + costs[1], 
                    cost[max(0, currDay - 30)] + costs[2]
                });
                travelIdx++;
            }
        }

        return cost[lastDay];
    }
};