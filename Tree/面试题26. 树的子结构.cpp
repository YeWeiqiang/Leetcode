/**
 * 面试题26. 树的子结构
 */



class Solution {
public:
    bool help(TreeNode* A, TreeNode* B){
        if(A == NULL || B == NULL){
            return B==NULL?true:false;
        }
        if(A->val != B->val) return false;

        return help(A->left, B->left) && help(A->right, B->right);
    }
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if(A == NULL || B == NULL) return false;

        return help(A, B) || isSubStructure(A->left, B) || isSubStructure(A->right, B);
    }
};