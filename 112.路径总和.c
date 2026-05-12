/*
 * @lc app=leetcode.cn id=112 lang=c
 *
 * [112] 路径总和
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
void preorder(struct TreeNode *node, int targetSum, int currentSum, bool *isHave)
{
    if (node == NULL || *isHave)
        return;

    currentSum = currentSum + node->val;

    if (node->left == NULL && node->right == NULL && currentSum == targetSum)
        (*isHave) = true;

    preorder(node->left, targetSum, currentSum, isHave);
    preorder(node->right, targetSum, currentSum, isHave);
}

bool hasPathSum(struct TreeNode *root, int targetSum)
{
    bool isHave = false;
    preorder(root, targetSum, 0, &isHave);
    return isHave;
}
// @lc code=end
