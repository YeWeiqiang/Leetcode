/**
 * 122. 买卖股票的最佳时机 II
 */



class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n <= 1) return 0;
        int res = 0;
        for(int i = 1; i < n; i++){
            if(prices[i] > prices[i-1]){
                res += prices[i]-prices[i-1];

            }
        }


        return res;
    }
};
/**
 * 时间：O(n)
 * 空间：O(1)
 */