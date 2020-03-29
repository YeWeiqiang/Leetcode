#include<iostream>
#include<vector>
using namespace std;

int partition(vector<int>& v, int left, int right)
{
    int temp = v[left];
    while(left < right)
    {
        while(left < right && v[right] >= temp) right--;
        v[left] = v[right];
        while(left < right && v[left] < temp) left++;
        v[right] = v[left];
    }
    v[left] = temp;

    return left;
}

void quickSort(vector<int>& v, int left, int right)
{
    if(left < right){
        int i = partition(v, left, right);
        quickSort(v, left, i-1);
        quickSort(v, i+1, right);
    }
}

int main()
{
    vector<int> v = {8, 1, 14, 3, 21, 5, 7, 10};
    quickSort(v, 0, v.size()-1);
    for(int i = 0; i < v.size(); i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;

    return 0;
}