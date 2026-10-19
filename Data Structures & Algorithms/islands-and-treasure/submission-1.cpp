class Solution {
   public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        // multi source BFS starting at all treasures
        // add +1 to each

        queue<pair<int, int>> q;
        // add every treasure
        int n = grid.size();
        int m = grid[0].size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 0) q.push({i, j});
            }
        }

        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                auto [x, y] = q.front();
                q.pop();

                // push neighbours
                const int dx[4] = {1, 0, -1, 0};
                const int dy[4] = {0, -1, 0, 1};
                for (int dir = 0; dir < 4; dir++) {
                    int x2 = x + dx[dir];
                    int y2 = y + dy[dir];
                    if (x2 < 0 || x2 >= n || y2 < 0 || y2 >= m)
                        continue;
                    else if (grid[x2][y2] == -1 || grid[x2][y2] != INT_MAX)
                        continue;
                    else {
                        grid[x2][y2] = grid[x][y] + 1;
                        q.push({x2, y2});
                    }
                }
            }
        }
    }
};
