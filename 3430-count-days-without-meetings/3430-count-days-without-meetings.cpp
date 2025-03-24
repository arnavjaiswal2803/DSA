class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        int n = meetings.size(), freeDays = days;

        sort(meetings.begin(), meetings.end());
        for (int i = 0; i < n; i++) {
            int start = meetings[i][0], end = meetings[i][1];
            while (i < n - 1 && meetings[i + 1][0] <= end) {
                end = max(end, meetings[i + 1][1]);
                i++;
            }
            freeDays -= (end - start + 1);
        }

        return freeDays;
    }
};