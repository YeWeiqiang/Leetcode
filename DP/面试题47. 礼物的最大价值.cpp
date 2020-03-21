/**
 * 面试题47. 礼物的最大价值
 */



class Solution {
public:
    int maxValue(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(i == 0 && j != 0){
                    grid[i][j] += grid[i][j-1];
                }else if(i != 0 && j == 0){
                    grid[i][j] += grid[i-1][j];
                }else if(i != 0 && j != 0){
                    grid[i][j] += max(grid[i-1][j], grid[i][j-1]);
                }
            }
        }

        return grid[m-1][n-1];
    }
};
/**
 * 时间： O(n)
 * 空间：O(1)
 */