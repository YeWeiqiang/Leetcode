#include "../header.h"

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<>> pque;
        for(auto num : nums){
            pque.push(num);
            if(pque.size() > k){
                pque.pop();
            }
        }

        return pque.top();
    }
};

int main()
{
    vector<int> v = {3,2,1,5,6,4};
    Solution* solution = new Solution();
    cout<<solution->findKthLargest(v, 2)<<endl;;
//	for(int i = 0; i < 6; i++){
//		cout<<a[i]<<" ";
//	}
//	cout<<endl;

    return 0;
}

