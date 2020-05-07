#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int rand5()
{
    return rand()%5+1;
}

//int rand7()
//{
//    vector<vector<int>> v = {
//            {1, 2, 3, 4, 5},
//            {6, 7, 1, 2, 3},
//            {4, 5, 6, 7, 1},
//            {2, 3, 4, 5, 6},
//            {7, 0, 0, 0, 0}
//    };
//
//    int res = 0;
//    while(res == 0)
//    {
//        int i = rand5();
//        int j = rand5();
//        res = v[i-1][j-1];
//    }
//
//    return res;
//}

int rand7()
{
    int i;
    do{
        i = 5*(rand5()-1)+rand5();
    }while(i > 21);

    return i%7+1;
}

int main()
{
    int size = 1000000;
    vector<int> v(10);
    for(int i = 0; i < size; i++){
        v[rand7()]++;
    }
    for(int i = 1; i <= 7; i++){
        cout<<1.0*v[i]/size<<endl;
    }

    return 0;
}