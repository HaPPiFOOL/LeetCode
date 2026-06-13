/*
 * @lc app=leetcode.cn id=404 lang=c
 *
 * [404] 左叶子之和
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
int sumOfLeftLeaves(struct TreeNode *root)
{
    // 递归出口
    if (NULL == root)
    {
        return 0;
    }

    // 处理左侧叶节点值
    int sum = 0;
    if (NULL != root->left)
    {
        if (NULL == root->left->left && NULL == root->left->right)
        {
            sum = root->left->val;
        }
    }

    // 相信函数能返回该节点所有左侧叶节点的值
    sum += sumOfLeftLeaves(root->left);
    sum += sumOfLeftLeaves(root->right);
    return sum;
}
// @lc code=end
