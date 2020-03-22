/**
 * 33. 搜索旋转排序数组
 */


class Solution {
public:
    int search(vector<int> &nums, int target) {
        int left = 0, right = nums.size()-1, mid;

        while(left < right)
        {
            mid = (left + right)/2;
            /**
             * 判断 mid 左边区域
             * (nums[left] <= target && target <= nums[mid]):不包含旋转点
             * (nums[mid] < nums[0] && nums[0] <= target)：包含旋转点，target在旋转部分
             * (nums[mid] < nums[0] && target <= nums[mid])：包含旋转点，target在非旋转部分
             */
            if(
                    (nums[left] <= target && target <= nums[mid]) ||
                    (nums[mid] < nums[0] && nums[0] <= target) ||
                    (nums[mid] < nums[0] && target <= nums[mid])){

                right = mid;

            }else{
                left = mid + 1;
            }
        }


        return (left == right && nums[left] == target)?left:-1;
    }
};