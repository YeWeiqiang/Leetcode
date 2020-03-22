/**
 * 300. 最长上升子序列
 */



class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if(n <= 1) return n;
        vector<int> tail;
        tail.push_back(nums[0]);

        for(int i = 1; i < n; i++){
            if(nums[i] > tail.back()){
                tail.push_back(nums[i]);
            }
            int end = tail.size();
            int left(0), right(end);
            while(left < right){
                int mid = (left + right) >> 1;
                if(tail[mid] < nums[i]){
                    left = mid+1;
                }else{
                    right = mid;
                }
            }
            tail[left] = nums[i];
        }

        return tail.size();
    }
};
/**
 * 时间：O(NlogN)
 * 空间：O(N)
 *
 * 参考:https://leetcode-cn.com/problems/longest-increasing-subsequence/solution/dong-tai-gui-hua-er-fen-cha-zhao-tan-xin-suan-fa-p/
 *
 */
