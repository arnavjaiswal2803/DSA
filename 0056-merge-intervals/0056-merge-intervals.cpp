class Solution {
    bool doesOverlap(vector<int>& a, vector<int>& b) {
        int s1 = a[0], e1 = a[1];
        int s2 = b[0], e2 = b[1];
        return s2 <= e1 && s1 <= e2;
    }
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<vector<int>> merged;

        sort(intervals.begin(), intervals.end());

        merged.push_back(intervals[0]);
        for (int i = 1; i < n; i++) {
            if (!doesOverlap(merged.back(), intervals[i])) 
                merged.push_back(intervals[i]);
            else {
                vector<int> newInterval = {
                    min(merged.back()[0], intervals[i][0]),
                    max(merged.back()[1], intervals[i][1])
                };
                merged.pop_back();
                merged.push_back(newInterval);
            } 
        }

        return merged;
    }
};