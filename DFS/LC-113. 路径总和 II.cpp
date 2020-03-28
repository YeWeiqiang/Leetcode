/**
 * 113. 路径总和 II == 面试题34. 二叉树中和为某一值的路径
 *
 */



class Solution {
public:
    void dfs(TreeNode* root, int sum, vector<vector<int>>& res, vector<int>& v){
        if(root == NULL) return;
        v.push_back(root->val);
        sum -= root->val;

        if(root->left == NULL && root->right == NULL){
            if(sum == 0){
                res.push_back(v);
            }
            return;
        }
        if(root->left != NULL){
            dfs(root->left, sum, res, v);
            v.pop_back();
        }
        if(root->right != NULL){
            dfs(root->right, sum, res, v);
            v.pop_back();
        }

    }
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
        vector<int> v;
        if(root == NULL) return res;
        dfs(root, sum, res, v);
        return res;
    }
};