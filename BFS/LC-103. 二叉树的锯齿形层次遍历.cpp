/**
 * 103. 二叉树的锯齿形层次遍历 == 面试题32 - III. 从上到下打印二叉树 III
 *
 */


class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(root == NULL) return res;

        queue<TreeNode*> que;
        que.push(root);
        bool LeftToRight = true;
        while(!que.empty())
        {
            int n = que.size();
            vector<int> temp;

            if(LeftToRight){
                while(n--)
                {
                    TreeNode* node = que.front();
                    que.pop();
                    temp.push_back(node->val);
                    if(node->left != NULL) que.push(node->left);
                    if(node->right != NULL) que.push(node->right);
                }
                LeftToRight = false;

            }else{
                while(n--)
                {
                    TreeNode* node = que.front();
                    que.pop();
                    temp.insert(temp.begin(), node->val);
                    if(node->left != NULL) que.push(node->left);
                    if(node->right != NULL) que.push(node->right);
                }
                LeftToRight = true;

            }

            res.push_back(temp);
        }

        return res;
    }
};