/**
 * 746. 使用最小花费爬楼梯
 */

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        if(n == 1 || n == 2){
            return cost[n];
        }

        vector<int> dp(n);
        dp[0] = cost[0];
        dp[1] = cost[1];
        for(int i = 2; i< n; i++){
            dp[i] = cost[i] + min(dp[i-1], dp[i-2]);
        }

        return min(dp[n-2], dp[n-1]);
    }
};
/**
 * 时间：O(n)
 * 空间：O(n)
 */


class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        if(n == 1 || n == 2){
            return cost[n];
        }

        int temp1 = cost[0], temp2 = cost[1];
        for(int i = 2; i< n; i++){
            temp1 = cost[i] + min(temp1, temp2);
            int temp = temp1;
            temp1 = temp2;
            temp2 = temp;
        }

        return min(temp1, temp2);
    }
};
/**
 * 时间：O(n)
 * 空间：O(1)
 */