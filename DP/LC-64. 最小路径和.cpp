/**
 * 64. 最小路径和
 */


class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();          //获取行数
        int n = grid[0].size();       //获取列数

        long long int a[m+1][n+1];

        a[0][0] = grid[0][0];
        for(int i = 1; i < m; i++){
            a[i][0] = a[i-1][0] + grid[i][0];
        }
        for(int j = 1; j < n; j++){
            a[0][j] = a[0][j-1] + grid[0][j];
        }
        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                a[i][j] = min(a[i-1][j], a[i][j-1]) + grid[i][j];

            }
        }


        return a[m-1][n-1];
    }
};
/**
 * 时间：O(mn)
 * 空间：O(mn)
 */



class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();          //获取行数
        int n = grid[0].size();       //获取列数
        int dp[n];
        dp[0] = grid[0][0];
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                //第一行但不是第一列
                if(i == 0 && j != 0){
                    dp[j] = grid[i][j] + dp[j-1];
                }
                    //第一列但不是第一行
                else if(i != 0 && j == 0){
                    dp[j] = grid[i][j] + dp[j];
                }
                    //既不是最后一行也不是最后一列
                else if(i != 0 && j != 0){
                    dp[j] = grid[i][j] + min(dp[j], dp[j-1]);
                }
            }
        }

        return dp[n-1];
    }
};
/**
 * 时间：O(mn)
 * 空间：O(n)
 */



class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();          //获取行数
        int n = grid[0].size();       //获取列数
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                //第一行但不是第一列
                if(i == 0 && j != 0){
                    grid[i][j] = grid[i][j] + grid[i][j-1];
                }
                //第一列但不是第一行
                else if(i != 0 && j == 0){
                    grid[i][j] = grid[i][j] + grid[i-1][j];
                }
                //既不是第一行也不是第一列
                else if(i != 0 && j != 0){
                    grid[i][j] = grid[i][j] + min(grid[i-1][j], grid[i][j-1]);
                }
            }
        }

        return grid[m-1][n-1];
    }
};
/**
 * 时间：O(mn)
 * 空间：O(1)
 */