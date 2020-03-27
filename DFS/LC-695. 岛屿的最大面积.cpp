/**
 * 695. 岛屿的最大面积
 */


class Solution {
public:
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    int dfs(vector<vector<int>>& grid, int x, int y){
        int m = grid.size();
        int n = grid[0].size();
        if(grid[x][y] == 0) return 0;
        grid[x][y] = 0;

        int res = 0;
        for(int k = 0; k < 4; k++){
            int i = x + dx[k];
            int j = y + dy[k];
            if(i >= 0 && i < m && j >= 0 && j < n){
                if(grid[i][j] == 0) continue;
                res += 1 + dfs(grid, i, j);
            }
        }

        return res;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        if(m == 0) return 0;
        int n = grid[0].size();

        int res = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                int curr = 0;
                if(grid[i][j] == 1){
                    curr = dfs(grid, i, j) + 1;
                }
                res = max(curr, res);
            }
        }

        return res;
    }
};

/**
 * 时间：O(mn)
 * 空间：O(mn) 递归的深度最大可能是整个网格的大小，因此最大可能使用 O(mn) 的栈空间
 */