/**
 * 105. 从前序与中序遍历序列构造二叉树
 */


class Solution {
public:
    TreeNode* build(vector<int>& preorder, int pos, vector<int>& inorder, int left, int right){
        // cout<<pos<<"  left:"<<left<<"  right:"<<right<<endl;
        if(left > right || left >=preorder.size() || right < 0) return NULL;

        int i = left, count = 0;
        while(preorder[pos] != inorder[i]){
            i++;
            count++;
        }
        TreeNode* node = new TreeNode(preorder[pos]);
        //pos+1：左子树中点的位置，left——i-1之间为左树枝
        node->left = build(preorder, pos+1, inorder, left, i-1);
        //pos+count+1：右子树中点的位置，i+1——right之间为右树枝
        //右子树中点 = 当前中点及其左子树的位置（利用中序遍历）+1
        node->right = build(preorder, pos+count+1, inorder, i+1, right);
        return node;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int pos = 0;
        return build(preorder, pos, inorder, 0, inorder.size()-1);
    }
};