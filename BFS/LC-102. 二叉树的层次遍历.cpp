/**
 * 102. 二叉树的层次遍历
 */


class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(root == NULL) return res;

        queue<TreeNode*> que;
        que.push(root);
        while(!que.empty())
        {
            int n = que.size();
            vector<int> temp;
            for(int i = 0; i < n; i++){
                TreeNode* node = que.front();
                que.pop();
                temp.push_back(node->val);
                if(node->left != NULL) que.push(node->left);
                if(node->right != NULL) que.push(node->right);
            }
            res.push_back(temp);
        }

        return res;
    }
};