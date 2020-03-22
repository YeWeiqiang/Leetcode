/**
 * 154. 寻找旋转排序数组中的最小值 II == 面试题11. 旋转数组的最小数字
 * 包含重复数组，加多一个 else if 判断
 *
 */

class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        int mid;
        while (left < right) {
            mid = (right + left)/2;

            if (nums[right] > nums[mid]) {
                right = mid;
            } else if(nums[right] == nums[mid]){
                right = right - 1;
            } else {
                left = mid + 1;
            }
        }

        return nums[left];
    }
};