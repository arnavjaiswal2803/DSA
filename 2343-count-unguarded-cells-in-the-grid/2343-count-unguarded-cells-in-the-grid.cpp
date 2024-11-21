class Solution {
    const int UNGUARDED = 0;
    const int GUARDED = 1;
    const int GUARD = 2;
    const int WALL = 3;

    void markWalls(vector<vector<int>> &cells, vector<vector<int>> &walls) {
        int wallsCount = walls.size();
        for (int i = 0; i < wallsCount; i++) {
            int wallRow = walls[i][0], wallCol = walls[i][1];
            cells[wallRow][wallCol] = WALL;
        }
    }

    void markGuards(vector<vector<int>> &cells, vector<vector<int>> &guards) {
        int guardsCount = guards.size();
        for (int i = 0; i < guardsCount; i++) {
            int guardRow = guards[i][0], guardCol = guards[i][1];
            cells[guardRow][guardCol] =  GUARD;
        }
    }

    bool updateCellVisibility( vector<vector<int>> &cells, int row, int col, bool isGuardLineActive) {
        if (cells[row][col] == GUARD) return true;
        if (cells[row][col] == WALL) return false;
        if (isGuardLineActive) cells[row][col] = GUARDED;
        return isGuardLineActive;
    }

    void markGuardedCells(int m, int n, vector<vector<int>> &cells) {
        for (int row = 0; row < m; row++) {
            bool isGuardLineActive = cells[row][0] == GUARD;
            for (int col = 1; col < n; col++) 
                isGuardLineActive = updateCellVisibility(cells, row, col, isGuardLineActive);

            isGuardLineActive = cells[row][n - 1] == GUARD;
            for (int col = n - 2; col >= 0; col--) 
                isGuardLineActive = updateCellVisibility(cells, row, col, isGuardLineActive);
        }

        for (int col = 0; col < n; col++) {
            bool isGuardLineActive = cells[0][col] == GUARD;
            for (int row = 1; row < m; row++) 
                isGuardLineActive = updateCellVisibility(cells, row, col, isGuardLineActive);

            isGuardLineActive = cells[m - 1][col] == GUARD;
            for (int row = m - 2; row >= 0; row--) 
                isGuardLineActive = updateCellVisibility(cells, row, col, isGuardLineActive);
        }
    }

    int countUnguardedCells(int m, int n, vector<vector<int>> &cells) {
        int unguardedCells = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) if (cells[i][j] == UNGUARDED) unguardedCells++;
        }
        return unguardedCells;
    }
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> cells(m, vector<int>(n, UNGUARDED));
        markWalls(cells, walls);
        markGuards(cells, guards);
        markGuardedCells(m, n, cells);
        return countUnguardedCells(m, n, cells);
    }
};