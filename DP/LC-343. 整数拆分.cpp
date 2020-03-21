/**
 * 343. 整数拆分 == 面试题14- I. 剪绳子
 */


class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n+1, 1);
        for(int i = 3; i <= n; i++){
            for(int j = 1; j < i; j++){
                /**
                 * j * (i - j)不一定是最大乘积，因为i-j不一定大于dp[i - j]
                 * （数字i-j拆分成整数之和的最大乘积），这里要选择最大的值作
                 * 为 dp[i] 的结果。
                 */
                dp[i] = max(max(dp[i], j*(i-j)), j*dp[i-j]);
            }
        }

        return dp[n];
    }
};
/**
 * 时间： O(n^2)
 * 空间：O(n)
 */



/**
 * 贪心
 * 时间： O(n)
 * 空间：O(1)
 */