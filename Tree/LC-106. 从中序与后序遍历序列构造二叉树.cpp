/**106. 从中序与后序遍历序列构造二叉树
 *
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
    TreeNode* build(vector<int>& inorder, int pos, vector<int>& postorder, int left, int right){
        if(left > right || right < 0 || left >= postorder.size()) return NULL;

        int i = right, count = 0;
        while(postorder[pos] != inorder[i]){
            i--;
            count++;
        }
        TreeNode* node = new TreeNode(postorder[pos]);
        node->left = build(inorder, pos-count-1, postorder, left, i-1);
        node->right = build(inorder, pos-1, postorder, i+1, right);

        return node;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int pos = postorder.size()-1;
        return build(inorder, pos, postorder, 0, postorder.size()-1);
    }
};