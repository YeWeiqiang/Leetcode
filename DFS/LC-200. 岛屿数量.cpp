/**
 * 200. 岛屿数量
 */

class Solution {
public:
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

    void dfs(vector<vector<char>>& grid, int i, int j){
        int m = grid.size();
        int n = grid[0].size();
        if(grid[i][j] == '0') return;
        grid[i][j] = '0';

        for(int k = 0; k < 4; k++){
            int x = i + dx[k];
            int y = j + dy[k];
            if(x >= 0 && y >= 0 && x < m && y < n){
                if(grid[x][y] == '0') continue;
                dfs(grid, x, y);
            }
        }
        return;
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        if(m == 0) return 0;
        int n = grid[0].size();

        int res = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == '1'){
                    dfs(grid, i, j);
                    res++;
                }
            }
        }

        return res;
    }
};