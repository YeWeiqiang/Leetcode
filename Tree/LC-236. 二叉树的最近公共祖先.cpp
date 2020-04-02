/**
 * 236. 二叉树的最近公共祖先 == 面试题68 - II. 二叉树的最近公共祖先
 */


class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL) return NULL;
        if(root == q || root == p) return root;

        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        if(left == NULL)    return right;
        if(right == NULL)   return left;
        if(left && right) return root;

        return NULL;
    }
};