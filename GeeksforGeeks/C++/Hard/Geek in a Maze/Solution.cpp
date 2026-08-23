class Solution {
  public:
    int numberOfCells(int r, int c, int u, int d, vector<vector<char>> &mat) {
        int n = mat.size(), m = mat[0].size();
        if (mat[r][c] == '#') return 0;

        vector<vector<int>> minUp(n, vector<int>(m, INT_MAX));
        // Use pair<int, int> instead of vector<int> for optimization
        queue<pair<int, int>> q;

        minUp[r][c] = 0;
        q.push({r, c});

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            for (int k = 0; k < 4; k++) {
                int nx = x + dr[k];
                int ny = y + dc[k];

                if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
                    continue;
                }
                if (mat[nx][ny] == '#') continue;

                int newUp = minUp[x][y];
                if (nx < x) newUp++; // Moving up increases up-count

                if (newUp > u) continue;

                if (newUp < minUp[nx][ny]) {
                    minUp[nx][ny] = newUp;
                    q.push({nx, ny});
                }
            }
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (minUp[i][j] == INT_MAX) continue;
                int up = minUp[i][j];
                int down = up + i - r; 
                if (down <= d) ans++;
            }
        }
        return ans;
    }
};