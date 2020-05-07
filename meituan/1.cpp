#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n, x;
    cin>>n>>x;
    vector<int> v(n);
    for(int i = 0; i < n; i++){
        cin>>v[i];
    }
    sort(v.begin(), v.end());
//    for(int i = 0; i < n; i++){
//        cout<<v[i]<<" ";
//    }
//    cout<<endl;
    int left = 0, right = n-1;
    int res = 0;
    while(left < right && (v[right] - v[left] > x))
    {
        int temp = (v[right] - v[right-1]) - (v[left+1] - v[left]);
        if(temp > 0){
            right--;
        }else{
            left++;
        }
//        cout<<left<<":"<<right<<endl;
        res++;
    }
    if(left == right) res = 0;

    cout<<res<<endl;

    return 0;
}