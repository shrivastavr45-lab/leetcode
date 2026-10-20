#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int row, col;
    vector<vector<int>> pacific, atlantic;

    void dfs(vector<vector<int>>& heights, int r, int c,
             vector<vector<int>>& visited) {
        visited[r][c] = 1;

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        for (int k = 0; k < 4; k++) {
            int nr = r + dr[k];
            int nc = c + dc[k];

            if (nr >= 0 && nc >= 0 && nr < row && nc < col &&
                !visited[nr][nc] &&
                heights[nr][nc] >= heights[r][c]) {
                dfs(heights, nr, nc, visited);
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        row = heights.size();
        col = heights[0].size();

        pacific.assign(row, vector<int>(col, 0));
        atlantic.assign(row, vector<int>(col, 0));

        for (int i = 0; i < row; i++) {
            dfs(heights, i, 0, pacific);
            dfs(heights, i, col - 1, atlantic);
        }

        for (int j = 0; j < col; j++) {
            dfs(heights, 0, j, pacific);
            dfs(heights, row - 1, j, atlantic);
        }

        vector<vector<int>> result;

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (pacific[i][j] && atlantic[i][j]) {
                    result.push_back({i, j});
                }
            }
        }

        return result;
    }
};

