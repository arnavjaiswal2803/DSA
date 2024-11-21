class Solution {
    void markWalls(vector<vector<int>> &cells, vector<vector<int>> &walls) {
        int wallsCount = walls.size();
        for (int i = 0; i < wallsCount; i++) {
            int wallRow = walls[i][0], wallCol = walls[i][1];
            cells[wallRow][wallCol] = -1;
        }
    }

    void markGuards(vector<vector<int>> &cells, vector<vector<int>> &guards) {
        int guardsCount = guards.size();
        for (int i = 0; i < guardsCount; i++) {
            int guardRow = guards[i][0], guardCol = guards[i][1];
            cells[guardRow][guardCol] = -1;
        }
    }

    void markGuardedCells(int m, int n, vector<vector<int>> &cells, vector<vector<int>> &guards) {
        int guardsCount = guards.size();
        for (int i = 0; i < guardsCount; i++) {
            int guardRow = guards[i][0], guardCol = guards[i][1];

            for (int col = guardCol + 1; col < n; col++) {
                if (cells[guardRow][col] == -1) break;
                else cells[guardRow][col] = 0;
            }
            for (int col = guardCol - 1; col >= 0; col--) {
                if (cells[guardRow][col] == -1) break;
                else cells[guardRow][col] = 0;
            }
            for (int row = guardRow + 1; row < m; row++) {
                if (cells[row][guardCol] == -1) break;
                else cells[row][guardCol] = 0;
            }
            for (int row = guardRow - 1; row >= 0; row--) {
                if (cells[row][guardCol] == -1) break;
                else cells[row][guardCol] = 0;
            }
        }
    }

    int countUnguardedCells(int m, int n, vector<vector<int>> &cells) {
        int unguardedCells = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) if (cells[i][j] == 1) unguardedCells++;
        }
        return unguardedCells;
    }
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> cells(m, vector<int>(n, 1));
        markWalls(cells, walls);
        markGuards(cells, guards);
        markGuardedCells(m, n, cells, guards);
        return countUnguardedCells(m, n, cells);
    }
};