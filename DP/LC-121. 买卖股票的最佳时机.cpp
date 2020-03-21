/**
 * 121. 买卖股票的最佳时机 == 面试题63. 股票的最大利润
 */


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n <= 1) return 0;
        int res = 0;
        int dp = prices[0];

        for(int i = 1; i < n; i++){
            if(prices[i] > dp){
                res = (prices[i]-dp)>res?(prices[i]-dp):res;
            }else{
                dp = prices[i];
            }
        }

        if(res < 0) return 0;
        else return res;
    }
};
/**
 * 时间：O(n)
 * 空间：O(1)
 */