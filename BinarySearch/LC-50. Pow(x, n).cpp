/**
 * 50. Pow(x, n)
 *
 */


class Solution {
public:
    double myPow(double x, int n) {
        long long N = n;
        if(n < 0){
            x = 1/x;
            N = -N;
        }

        double temp = x, res = 1;
        for(long long i = N; i > 0; i >>= 1){
            if(i % 2 == 1){
                res *= temp;
            }
            temp *= temp;
        }

        return res;
    }
};
