/**
 * 103. 二叉树的锯齿形层次遍历 == 面试题32 - III. 从上到下打印二叉树 III
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(root == NULL) return res;
        deque<TreeNode*> que;
        que.push_back(root);
        bool RIGHT_TO_LEFT = false;

        while(!que.empty())
        {
            int n = que.size();
            vector<int> temp;
            if(RIGHT_TO_LEFT){
                int i = 0;
                while(i < n)
                {
                    TreeNode* t = que.back();
                    temp.push_back(t->val);
                    que.pop_back();
                    if(t->right != NULL) que.push_front(t->right);
                    if(t->left != NULL) que.push_front(t->left);
                    i++;
                }

                RIGHT_TO_LEFT = false;
            }else{
                int i = 0;
                while(i < n)
                {
                    TreeNode* t = que.front();
                    temp.push_back(t->val);
                    que.pop_front();
                    if(t->left != NULL) que.push_back(t->left);
                    if(t->right != NULL) que.push_back(t->right);
                    i++;
                }

                RIGHT_TO_LEFT = true;
            }

            res.push_back(temp);
        }

        return res;
    }
};