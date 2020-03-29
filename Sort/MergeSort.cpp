#include<iostream>
#include<vector>
using namespace std;

void merge(vector<int>& v, int left, int mid, int right)
{
    vector<int> temp;
    int i = left, j = mid+1;
    while(i <= mid && j <= right)
    {
        if(v[i] > v[j]) {
            temp.push_back(v[j]);
            j++;
        }else{
            temp.push_back(v[i]);
            i++;
        }
    }
    while(i <= mid)
    {
        temp.push_back(v[i]);
        i++;
    }
    while(j <= right)
    {
        temp.push_back(v[j]);
        j++;
    }

    for(int i = 0; i < temp.size(); i++){
        v[left + i] = temp[i];
    }
}

void mergeSort(vector<int>& v, int left, int right)
{
    if(left >= right) return;

    int mid = (left + right) / 2;
    mergeSort(v, left, mid);
    mergeSort(v, mid+1, right);

    merge(v, left, mid, right);
}

int main()
{
    vector<int> v = {8, 1, 14, 3, 21, 5, 7, 10};
    mergeSort(v, 0, v.size()-1);
    for(int i = 0; i < v.size(); i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;

    return 0;
}