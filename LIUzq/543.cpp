//543.二叉树的直径

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
    int res;
    int diameterOfBinaryTree(TreeNode* root) {
        res = 1;
        //int n = depth(root);
        depth(root);        //这里并不需要加入 n = depth（root）；属于递归调用，最终返回值是在函数内部的L,R
        return res - 1;
    }
private:
    int depth(TreeNode* node){
        if(node == NULL) return 0;
        int L = depth(node->left);
        int R = depth(node->right);
        //每个节点的最大直径通过的节点数（最大直径=节点数-1）,假设根节点的深度为1；
        res = max(res, L + R + 1);
        return max(L,R) + 1;
    }
};