/**
 * 94. 二叉树的中序遍历
 *
 */


class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        if(root == NULL) return res;
        stack<TreeNode*> s;
        TreeNode* p = root;
        while(p != NULL || !s.empty())
        {
            while(p != NULL){
                s.push(p);
                p = p->left;
            }
            p = s.top();
            s.pop();
            res.push_back(p->val);
            p = p->right;
        }

        return res;
    }
};