class Solution {
    double getLowerMinusUpperArea(vector<vector<int>>& squares, double mid) {
        double lowerArea = 0, upperArea = 0;

        for (auto &square : squares) {
            double lowerY = square[1], sideLen = square[2], upperY = lowerY + sideLen;

            if (upperY <= mid) {
                lowerArea += (sideLen * sideLen);
            } else if (lowerY >= mid) {
                upperArea += (sideLen * sideLen);
            } else {
                lowerArea += (sideLen * (mid - lowerY));
                upperArea += (sideLen * (upperY - mid));
            }
        }

        return lowerArea - upperArea;
    }
public:
    double separateSquares(vector<vector<int>>& squares) {
        int n = squares.size();
        double low = INT_MAX, high = 0;

        for (auto &sq : squares) {
            low = min(low, (double)sq[1]);
            high = max(high, (double)sq[1] + (double)sq[2]);
        }
        
        while (high - low > 1e-5) {
            double mid = (low + high) / 2;

            if (getLowerMinusUpperArea(squares, mid) >= 0) high = mid;
            else low = mid;
        }

        return high;
    }
};