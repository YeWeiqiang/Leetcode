/**
 *  104. 二叉树的最大深度 == 面试题55 - I. 二叉树的深度
 */

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == NULL) return 0;

        return max(maxDepth(root->left)+1, maxDepth(root->right)+1);
    }
};