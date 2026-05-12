/*
 * @lc app=leetcode.cn id=110 lang=c
 *
 * [110] 平衡二叉树
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int height(struct TreeNode *node)
{
    if (node == NULL)
        return 0;

    int l = height(node->left);
    int r = height(node->right);

    // 只要有一个不平衡就全部不平衡
    if (l == -1 || r == -1 || l - r > 1 || l - r < -1)
        return -1;

    return l > r ? l + 1 : r + 1;
}
bool isBalanced(struct TreeNode *root)
{
    return height(root) >= 0;
}
// @lc code=end
