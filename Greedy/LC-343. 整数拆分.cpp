/**
 * 343. 整数拆分 == 面试题14- I. 剪绳子
 */


class Solution {
public:
    int integerBreak(int n) {
        if(n <= 3) return 1*(n-1);

        int result = 1;
        if(n%3 == 2){
            n -= 2;
            result *= 2;
        }

        if(n%3 == 1){
            n -= 4;
            result *= 4;
        }

        while(n > 0)
        {
            result *= 3;
            n -= 3;
        }

        return result;
    }
};