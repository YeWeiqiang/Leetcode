/**
 * 34. 在排序数组中查找元素的第一个和最后一个位置
 * == 面试题53 - I. 在排序数组中查找数字 I
 */


class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> res(2, -1);
        if(n < 1) return res;

        int left(0), right(n-1);
        int mid;

        while(left < right)
        {
            int mid = (left + right) >> 1;
            if(nums[mid] < target){
                left = mid + 1;
            }else{
                right = mid;
            }
        }

        if(nums[left] != target) return res;
        int i = left, j = right;
        while(i >= 0 && nums[i] == target){
            i--;
        }
        res[0] = i+1;
        while(j < nums.size() && nums[j] == target)
        {
            j++;
        }
        res[1] = j-1;


        return res;
    }
};