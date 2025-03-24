class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        vector<vector<int>> mergedMeetings = mergeIntervals(meetings);
        int freeDays = days;

        for (vector<int> &meeting : mergedMeetings) {
            freeDays -= (meeting[1] - meeting[0] + 1);
        }

        return freeDays;
    }

private:
    vector<vector<int>> mergeIntervals(vector<vector<int>>& meetings) {
        int m = meetings.size();
        vector<vector<int>> mergedMeetings;

        sort(meetings.begin(), meetings.end());
        mergedMeetings.push_back(meetings[0]);
        for (int i = 1; i < m; i++) {
            if (meetings[i][0] <= mergedMeetings.back()[1]) {
                mergedMeetings.back()[1] =
                    max(mergedMeetings.back()[1], meetings[i][1]);
            } else {
                mergedMeetings.push_back(meetings[i]);
            }
        }

        return mergedMeetings;
    }
};