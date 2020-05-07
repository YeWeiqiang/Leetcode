/**
 * 面试题40. 最小的k个数
 */


class Solution {
public:
    vector<int> getLeastNumbers(vector<int> &arr, int k) {
        vector<int> res(k, 0);
        if (k == 0) return res;
        priority_queue<int> pque;
        for (int i = 0; i < k; i++) pque.push(arr[i]);
        for (int i = k; i < arr.size(); i++) {
            if (pque.top() > arr[i]) {
                pque.pop();
                pque.push(arr[i]);
            }
        }
        for (int i = 0; i < k; i++) {
            res[i] = pque.top();
            pque.pop();
        }

        return res;
    }
};


class Solution {
public:
    vector<int> getLeastNumbers(vector<int> &arr, int k) {
        int n = arr.size();
        if (n == k) return arr;
        if (n < k || k <= 0 || n == 0) return vector<int>();
        int left = 0, right = n - 1;
        int index = partition(arr, left, right);
        while (index != k - 1) {
            if (index > k - 1) right = index - 1;
            else left = index + 1;
            index = partition(arr, left, right);
        }
        return vector<int>(arr.begin(), arr.begin() + k);
    }

    //快排partition函数
    int partition(vector<int> &arr, int left, int right) {
        int temp = arr[left];
        while (left < right) {
            while (left < right && arr[right] >= temp) right--;
            arr[left] = arr[right];
            while (left < right && arr[left] <= temp) left++;
            arr[right] = arr[left];
        }
        arr[left] = temp;
        return left;
    }

};


/**
 * https://www.cnblogs.com/walker-lee/p/5814505.html
 */
class Solution {
public:
    void adjust(vector<int> &max_heap, int len, int index) {
        int left = 2 * index + 1;
        int right = 2 * index + 2;

        int maxIndex = index;
        if (left < len && max_heap[left] > max_heap[maxIndex]) maxIndex = left;
        if (right < len && max_heap[right] > max_heap[maxIndex]) maxIndex = right;

        if (maxIndex != index) {
            swap(max_heap[maxIndex], max_heap[index]);
            adjust(max_heap, len, maxIndex);
        }
    }

    vector<int> getLeastNumbers(vector<int> &arr, int k) {
        if (k == 0) return {};

        vector<int> max_heap = vector<int>(arr.begin(), arr.begin() + k);
        //建堆
        for (int i = max_heap.size() / 2 - 1; i >= 0; i--) {
            adjust(max_heap, max_heap.size(), i);
        }

        for (int i = k; i < arr.size(); i++) {
            //若比大根堆的根节点要小，则调整大根堆
            if (arr[i] < max_heap[0]) {
                //替换根节点
                max_heap[0] = arr[i];
                //调整大根堆
                adjust(max_heap, max_heap.size(), 0);
            }
        }

        return max_heap;
    }
};