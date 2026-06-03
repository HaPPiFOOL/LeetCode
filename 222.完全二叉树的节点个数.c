/*
 * @lc app=leetcode.cn id=222 lang=c
 *
 * [222] 完全二叉树的节点个数
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
int countNodes(struct TreeNode *root)
{
    if (NULL == root)
        return 0;

    int count = 1 + countNodes(root->left) + countNodes(root->right);

    return count;
}
// @lc code=end
