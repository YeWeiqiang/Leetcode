#include "header.h"

void adjust(vector<int>& v, int len, int index)
{
    int left = 2*index+1;
    int right = 2*index+2;
    int maxIndex = index;

    if(left < len && v[left] > v[maxIndex]) maxIndex = left;
    if(right < len && v[right] > v[maxIndex]) maxIndex = right;

    if(maxIndex != index){
        swap(v[maxIndex], v[index]);
        adjust(v, len, maxIndex);
    }

}

void heapSort(vector<int>& v, int size)
{
    for(int i = size/2 - 1; i >= 0; i--){
        adjust(v, size, i);
    }

    for(int i = size-1; i >= 0; i--){
        swap(v[0], v[i]);
        adjust(v, i, 0);
    }

}

int main()
{
    vector<int> v = {8, 1, 14, 3, 21, 5, 7, 10};
    heapSort(v, v.size());
    for(int i = 0; i < v.size(); i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;

    return 0;

}