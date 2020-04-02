/**
 * 235. 二叉搜索树的最近公共祖先 == 面试题68 - I. 二叉搜索树的最近公共祖先
 *
 */



class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL) return NULL;

        if(root->val < p->val && root->val < q->val){
            return lowestCommonAncestor(root->right, p, q);
        }else if(root->val > p->val && root->val > q->val){
            return lowestCommonAncestor(root->left, p, q);
        }else{
            return root;
        }
    }
};