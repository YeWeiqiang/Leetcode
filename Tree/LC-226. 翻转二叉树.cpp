#include "../header.h"

/**
 * 226. 翻转二叉树 == 面试题27. 二叉树的镜像
 */


class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root == NULL) return NULL;

        TreeNode* left = invertTree(root->left);
        TreeNode* right = invertTree(root->right);
        root->left = right;
        root->right = left;

        return root;
    }
};