class Solution {
    const bool X_AXIS = true;
    const bool Y_AXIS = false;

    bool doesOverlap(vector<int>& a, vector<int>& b) {
        int s1 = a[0], e1 = a[1];
        int s2 = b[0], e2 = b[1];
        return s2 < e1 && s1 < e2;
    }

    vector<vector<int>> mergeIntervals(vector<vector<int>>& intervals) {
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

    bool canCut(vector<vector<int>>& rectangles, bool axis) {
        vector<vector<int>> coordinates;
        for (auto &rectangle : rectangles) {
            int coordinate1 = axis == X_AXIS ? 0 : 1;
            int coordinate2 = axis == X_AXIS ? 2 : 3;
            coordinates.push_back({rectangle[coordinate1], rectangle[coordinate2]});
        }
        sort(coordinates.begin(), coordinates.end());
        coordinates = mergeIntervals(coordinates);
        return coordinates.size() >= 3;
    }
public:
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        return canCut(rectangles, X_AXIS) || canCut(rectangles, Y_AXIS);
    }
};