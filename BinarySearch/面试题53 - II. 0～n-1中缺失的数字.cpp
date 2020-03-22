/**
 * 面试题53 - II. 0～n-1中缺失的数字
 * 考虑边界情况
 */


class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        //考虑[0],[0,1]等边界情况
        if(nums[n-1] == n-1) return n;
        int left(0), right(n-1);
        while(left < right)
        {
            int mid = (left + right) >> 1;
            if(nums[mid] == mid){
                left = mid + 1;
            }else{
                right = mid;
            }
        }

        return left;
    }
};