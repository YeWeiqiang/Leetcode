/**
 * 面试题40. 最小的k个数
 */


class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        vector<int> res(k, 0);
        if(k == 0) return res;
        priority_queue<int> pque;
        for(int i = 0; i < k; i++) pque.push(arr[i]);
        for(int i = k; i < arr.size(); i++){
            if(pque.top() > arr[i]){
                pque.pop();
                pque.push(arr[i]);
            }
        }
        for(int i = 0; i < k; i++)
        {
            res[i] = pque.top();
            pque.pop();
        }

        return res;
    }
};