/**
 * 46. 全排列
 */


class Solution {
public:
    vector<vector<int>> res;
    void dfs(vector<int>& nums, int level){
        if(level == nums.size()){
            res.push_back(nums);
            return;
        }
        for(int i = level; i < nums.size(); i++){
            swap(nums[i], nums[level]);
            dfs(nums, level+1);
            swap(nums[i], nums[level]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        dfs(nums, 0);
        return res;
    }
};