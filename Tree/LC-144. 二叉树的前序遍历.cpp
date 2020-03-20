/**
 * 144. 二叉树的前序遍历(非递归)
 */

 /**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root){
        vector<int> res;
        if(root == NULL) return res;
        stack<TreeNode*> s;
        s.push(root);
        while(!s.empty())
        {
            TreeNode* temp = s.top();
            s.pop();
            res.push_back(temp->val);
            if(temp->right != NULL){
                s.push(temp->right);
            }
            if(temp->left != NULL){
                s.push(temp->left);
            }

        }

        return res;
    }
};