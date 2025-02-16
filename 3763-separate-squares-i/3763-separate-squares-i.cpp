class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        double low = INT_MAX, high = 0;

        for (auto &sq : squares) {
            low = min(low, (double)sq[1]);
            high = max(high, (double)sq[1] + (double)sq[2]);
        }
        
        while (high - low > 1e-5) {
            double mid = (low + high) / 2;

            double lowerArea = 0, upperArea = 0;

            for (auto &square : squares) {
                double lowerY = square[1], sideLen = square[2], 
                    upperY = lowerY + sideLen;

                if (upperY <= mid) {
                    lowerArea += (sideLen * sideLen);
                } else if (lowerY >= mid) {
                    upperArea += (sideLen * sideLen);
                } else {
                    lowerArea += (sideLen * (mid - lowerY));
                    upperArea += (sideLen * (upperY - mid));
                }
            }

            upperArea > lowerArea ? low = mid : high = mid;
        }

        return high;
    }
};