/**
 * 107. 二叉树的层次遍历 II
 */


class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        if(root == NULL) return res;

        queue<TreeNode*> que;
        que.push(root);
        while(!que.empty())
        {
            int n = que.size();
            vector<int> temp;
            while(n--)
            {
                TreeNode* node = que.front();
                que.pop();
                temp.push_back(node->val);
                if(node->left != NULL) que.push(node->left);
                if(node->right != NULL) que.push(node->right);
            }
            res.insert(res.begin(), temp);  // <-------重点
        }

        return res;
    }
};