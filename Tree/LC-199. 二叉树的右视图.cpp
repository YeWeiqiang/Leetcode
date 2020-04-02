/**
 * 199. 二叉树的右视图
 */



class Solution {
public:
    void dfs(TreeNode* root, int level, vector<int>& res){
        if(!root) return;
        if(level == res.size()){
            res.push_back(root->val);
        }

        if(root->right != NULL) dfs(root->right, level+1, res);
        if(root->val != NULL) dfs(root->left, level+1, res);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if(root == NULL) return res;
        dfs(root, 0, res);

        return res;
    }
};