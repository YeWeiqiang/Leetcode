/**
 * 70. 爬楼梯
 */

class Solution {
public:
    int climbStairs(int n) {
        if(n == 1 || n == 2){
            return n;
        }
        vector<int> dp(n+1);
        dp[1] = 1;
        dp[2] = 2;
        for(int i = 3; i <= n; i++){
            dp[i] = dp[i-1] + dp[i-2];
        }

        return dp[n];
    }
};
/**
 * 时间：O(n)
 * 空间：O(n)
 */


class Solution {
public:
    int climbStairs(int n) {
        if(n == 1 || n == 2){
            return n;
        }
        int temp1 = 1, temp2 = 2;
        for(int i = 3; i <= n; i++){
            temp1 = temp1 + temp2;
            int temp = temp1;
            temp1 = temp2;
            temp2 = temp;
        }

        return temp2;
    }
};
/**
 * 时间：O(n)
 * 空间：O(1)
 */