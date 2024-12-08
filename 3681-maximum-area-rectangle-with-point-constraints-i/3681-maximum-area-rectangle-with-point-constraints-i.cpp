class Solution {
    bool isRectangle(vector<int>& A, vector<int>& D, vector<int>& B,
                     vector<int>& C) {
        bool val = A[0] == D[0] && B[0] == C[0] && A[1] == B[1] && C[1] == D[1];
        return val;
    }

    bool doesIntersect(vector<vector<int>>& points, int n, int A, int D, int B,
                       int C) {
        for (int i = 0; i < n; i++) {
            if (i != A && i != B && i != C && i != D &&
                points[i][0] >= points[A][0] && points[i][0] <= points[C][0] &&
                points[i][1] >= points[A][1] && points[i][1] <= points[C][1])
                return true;
        }
        return false;
    }

    int getArea(vector<int>& A, vector<int>& D, vector<int>& B,
                vector<int>& C) {
        return abs(C[0] - A[0]) * abs(C[1] - A[1]);
    }

public:
    int maxRectangleArea(vector<vector<int>>& points) {
        int n = points.size(), maxArea = -1;

        sort(points.begin(), points.end());
        for (int A = 0; A < n - 3; A++) {
            for (int B = A + 1; B < n - 2; B++) {
                for (int C = B + 1; C < n - 1; C++) {
                    for (int D = C + 1; D < n; D++) {
                        if (isRectangle(points[A], points[B], points[C],
                                        points[D]) &&
                            !doesIntersect(points, n, A, B, C, D)) {
                            maxArea =
                                max(maxArea, getArea(points[A], points[B],
                                                     points[C], points[D]));
                        }
                    }
                }
            }
        }

        return maxArea;
    }
};