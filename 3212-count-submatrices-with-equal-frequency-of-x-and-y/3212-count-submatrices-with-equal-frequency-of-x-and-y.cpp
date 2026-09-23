class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> x(n, vector<int>(m, 0));
        vector<vector<int>> y(n, vector<int>(m, 0));
        if (grid[0][0] == 'X') {
            x[0][0] = 1;
        } else if (grid[0][0] == 'Y') {
            y[0][0] = 1;
        }
        for (int i = 1; i < m; i++) {
            if (grid[0][i] == 'X') {
                x[0][i] = x[0][i - 1] + 1;
            } else {
                x[0][i] = x[0][i - 1];
            }

            if (grid[0][i] == 'Y') {
                y[0][i] = y[0][i - 1] + 1;
            } else {
                y[0][i] = y[0][i - 1];
            }
        }

        for (int i = 1; i < n; i++) {
            if (grid[i][0] == 'X') {
                x[i][0] = x[i - 1][0] + 1;
            } else {
                x[i][0] = x[i - 1][0];
            }

            if (grid[i][0] == 'Y') {
                y[i][0] = y[i - 1][0] + 1;
            } else {
                y[i][0] = y[i - 1][0];
            }
        }

        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                if (grid[i][j] == 'X') {
                    x[i][j] = x[i - 1][j] + x[i][j - 1] - x[i - 1][j - 1] + 1;

                } else {
                    x[i][j] = x[i - 1][j] + x[i][j - 1] - x[i - 1][j - 1];
                }
            }
        }

        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                if (grid[i][j] == 'Y') {
                    y[i][j] = y[i - 1][j] + y[i][j - 1] - y[i - 1][j - 1] + 1;

                } else {
                    y[i][j] = y[i - 1][j] + y[i][j - 1] - y[i - 1][j - 1];
                }
            }
        }

        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (x[i][j] > 0 && x[i][j] == y[i][j]) {
                    cnt++;
                }
            }
        }
        return cnt;
    }
};