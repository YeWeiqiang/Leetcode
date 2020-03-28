/**
 * 110. 平衡二叉树 == 面试题55 - II. 平衡二叉树
 *
 */


class Solution {
public:
    int dfs(TreeNode* root){
        if(root == NULL) return 0;
        int h1 = dfs(root->left) + 1;
        int h2 = dfs(root->right) + 1;

        return h1>=h2?h1:h2;
    }
    bool isBalanced(TreeNode* root) {
        if(root == NULL) return true;
        int left = dfs(root->left);
        int right = dfs(root->right);
        int d = abs(left - right);
        if(d > 1) return false;

        return isBalanced(root->left) && isBalanced(root->right);
    }
};