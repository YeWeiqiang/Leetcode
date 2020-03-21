/**
 * 152. 乘积最大子序列
 */


class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int maxV = nums[0];
        int minV = nums[0];
        int result = nums[0];
        for(int i = 1; i < n; i++){
            int temp = maxV;
            //之所以要判断nums[i]是因为排除nums[i-1]==0的可能
            maxV = max(max(maxV*nums[i], nums[i]), minV*nums[i]);
            minV = min(min(minV*nums[i], nums[i]), temp*nums[i]);
            result = max(maxV, result);
        }

        return result;
    }
};
/**
 * 时间：O(n)
 * 空间：O(1)
 */