class Solution {
public:
    long long coloredCells(int n) {
        long long middleRow = 2 * n - 1;
        long long upperPyramid = ((long long)n * (n - 1)) - (n - 1);
        long long lowerPyramid = upperPyramid;
        
        return middleRow + upperPyramid + lowerPyramid;
    }
};