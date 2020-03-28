/**
 * 199. 二叉树的右视图
 */

//定义一个level变量来判断同一层是否有右子树！
class Solution {
public:
    void dfs(TreeNode* root, int level, vector<int>& res){
        if(root == NULL) return;
        if(res.size() == level) res.push_back(root->val);
        dfs(root->right, level+1, res);
        dfs(root->left, level+1, res);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        dfs(root, 0, res);

        return res;
    }
};