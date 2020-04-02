/**
 * 783. 二叉搜索树结点最小距离
 */


class Solution {
public:
    int pre=NULL, ans=INT_MAX;
    int minDiffInBST(TreeNode* root) {
        if(root == NULL) return NULL;
        minDiffInBST(root->left);
        if(pre != NULL){
            ans = min(ans,root->val-pre);
        }
        pre = root->val;
        minDiffInBST(root->right);

        return ans;
    }
};