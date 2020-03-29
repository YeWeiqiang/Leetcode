/**
 *  堆排序
 *  参考：https://www.cnblogs.com/wanglei5205/p/8733524.html
 */
#include<iostream>
#include<vector>
using namespace std;

// 递归方式构建大根堆(len是arr的长度，index是第一个非叶子节点的下标)
void adjust(vector<int>& v, int len, int index){
    int left = 2*index + 1;
    int right = 2*index + 2;

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
    // 构建大根堆（从最后一个非叶子节点向上）
    //完全二叉树叶子节点数 = 总节点数 / 2，最后一个非叶子节点 = 总节点数/2 - 1
    for(int i = size/2 - 1; i >= 0; i--){
        adjust(v, size, i);
    }

    // 调整大根堆
    for(int i = size - 1; i >= 1; i--){
        swap(v[0], v[i]);   // 将当前最大的放置到数组末尾
        adjust(v, i, 0);  // 将未完成排序的部分继续进行堆排序
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
/**
 * 初始化建堆的时间复杂度为O(n)
 * 排序重建堆的时间复杂度为nlog(n)
 *
 * 总的时间复杂度为O(n+nlogn)=O(nlogn)。
 */




