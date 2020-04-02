/**
 * 145. 二叉树的后序遍历
 */



class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        if(root == NULL) return res;
        stack<TreeNode*> s;
        s.push(root);
        while(!s.empty())
        {
            TreeNode* temp = s.top();
            s.pop();
            res.insert(res.begin(), temp->val);
            if(temp->left != NULL)  s.push(temp->left);
            if(temp->right != NULL) s.push(temp->right);
        }

        return res;
    }
};