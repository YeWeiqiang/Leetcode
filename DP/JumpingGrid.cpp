/**
 *他们来到了一片空地，画了N个连续的方格，每个方格上随机填上了一个数字，
 * 大家从第一个格子开始，每次可以向后跳不超过当前格子上的数的步数，大
 * 家开始就此比赛，看谁跳到最后一个格子的步数最少。
 *
 */


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n,a,f[5005];

int main()
{
    vector<int> v = {2, 3, 1, 1, 1};
    int n = v.size();
    vector<int> dp(n, 127);

    dp[0] = 0;
    for(int i = 0; i < n; i++){
        for(int j = i+1; j <= i+v[i]; j++){
            if(j > n-1) break; //如果越界了就退出
            dp[j]=min(dp[j], dp[i]+1); //状态转移方程
            if(j == n-1){ //先到就直接输出
                cout<<dp[n-1]<<endl;
                return 0;
            }
        }
    }
    cout<<dp[n-1]<<endl;
    return 0;
}
