class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {

        int m = classroom.size();
        int n = classroom[0].size();

        int sr, sc;
        vector<pair<int,int>> litter;

        // Find S and all litter
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (classroom[i][j] == 'S') {
                    sr = i;
                    sc = j;
                }

                if (classroom[i][j] == 'L') {
                    litter.push_back({i, j});
                }
            }
        }

        int L = litter.size();
        int fullMask = (1 << L) - 1;

        // dist[r][c][energy][mask]
        vector<vector<vector<vector<int>>>> dist(
            m, vector<vector<vector<int>>>(
                n, vector<vector<int>>(
                    energy + 1, vector<int>(1 << L, -1)
                )
            )
        );

        queue<array<int,4>> q;

        dist[sr][sc][energy][0] = 0;
        q.push({sr, sc, energy, 0});

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        while (!q.empty()) {

            auto [r, c, e, mask] = q.front();
            q.pop();

            int moves = dist[r][c][e][mask];

            // Collected everything
            if (mask == fullMask)
                return moves;

            for (int d = 0; d < 4; d++) {

                int nr = r + dr[d];
                int nc = c + dc[d];

                // Outside grid
                if (nr < 0 || nr >= m || nc < 0 || nc >= n)
                    continue;

                // Obstacle
                if (classroom[nr][nc] == 'X')
                    continue;

                // Need energy to move
                if (e == 0)
                    continue;

                int ne = e - 1;
                int nmask = mask;

                // Collect litter
                for (int i = 0; i < L; i++) {
                    if (litter[i].first == nr &&
                        litter[i].second == nc) {
                        nmask |= (1 << i);
                    }
                }

                // Reset energy
                if (classroom[nr][nc] == 'R') {
                    ne = energy;
                }

                if (dist[nr][nc][ne][nmask] == -1) {

                    dist[nr][nc][ne][nmask] = moves + 1;

                    q.push({nr, nc, ne, nmask});
                }
            }
        }

        return -1;
    }
};