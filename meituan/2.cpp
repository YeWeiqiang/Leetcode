#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n, m;
    cin>>n>>m;
    vector<int> v(n);
    long long int sum = 0;
    int minV = INT_MIN;
    for(int i = 0; i < n; i++){
        cin>>v[i];
        sum += v[i];
        minV = min(v[i], minV);
    }

    int res = 0;
    while(m >= sum)
    {
        res += n;
        m -= sum;
    }
    int i = 0;
    while(m > 0 && m >= minV)
    {
        if(m > v[i]){
            m -= v[i];
            res++;
        }
        i = (i+1)%n;
    }
    cout<<res<<endl;

    return 0;
}