#include "header.h"



class Solution {
public:
    void dfs(vector<int>& nums, vector<vector<int>>& res, vector<int>& v, int index){
        if(v.size() > nums.size()){
            return;
        }else{
            res.push_back(v);
            for(int i = index; i < nums.size(); i++){
                v.push_back(nums[i]);
                dfs(nums, res, v, i+1);
                v.pop_back();
            }
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> res;
        if(n < 1) return res;
        vector<int> v;

        dfs(nums, res, v, 0);
        return res;
    }
};