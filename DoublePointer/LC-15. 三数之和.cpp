/**
 * 15. 三数之和
 */



/**
 *
遍历排序后数组：
若 nums[i]>0：因为已经排序好，所以后面不可能有三个数加和等于 0，直接返回结果。
对于重复元素：跳过，避免出现重复解
令左指针 L=i+1，右指针 R=n-1，当 L<R 时，执行循环：
当 nums[i]+nums[L]+nums[R]==0，执行循环，判断左界和右界是否和下一位置重复，去除重复解。并同时将 L,R 移到下一位置，寻找新的解
若和大于 0，说明 nums[R] 太大，R 左移
若和小于 0，说明 nums[L] 太小，L 右移

 */

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        int n = nums.size();
        if(n < 3) return res;
        sort(nums.begin(), nums.end());

        for(int i = 0; i < n-2; i++){
            if(nums[i] > 0) return res;
            //排除重复情况
            if(i > 0 && nums[i] == nums[i-1]) continue;

            int L = i+1, R = n-1;
            while(L < R)
            {
                int sum = nums[i] + nums[L] + nums[R];
                if(sum == 0){
                    res.push_back({nums[i], nums[L], nums[R]});
                    //排除重复情况
                    while(L < R && nums[L] == nums[++L]);
                    while(L < R && nums[R] == nums[--R]);

                }else if(sum < 0){
                    L++;
                }else{
                    R--;
                }
            }
        }

        return res;
    }
};