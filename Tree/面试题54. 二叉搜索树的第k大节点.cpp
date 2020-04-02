/**
 * 面试题54. 二叉搜索树的第k大节点
 */


class Solution {
public:
    int kthLargest(TreeNode* root, int k) {
        if(root == NULL) return -1;
        stack<TreeNode*> s;
        while(!s.empty() || root)
        {
            while(root != NULL){
                s.push(root);
                root = root->right;
            }
            root = s.top();
            s.pop();
            k--;
            if(k == 0) return root->val;
            root = root->left;
        }

        return 0;
    }
};