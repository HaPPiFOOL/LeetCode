/*
 * @lc app=leetcode.cn id=144 lang=c
 *
 * [144] 二叉树的前序遍历
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
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *preorderTraversal(struct TreeNode *root, int *returnSize)
{
    // 栈
    int top = -1;
    struct TreeNode *stack[101];
    // 结果
    int *retArr = (int *)malloc(sizeof(int) * 101);
    *returnSize = 0;

    while (NULL != root || top > -1)
    {
        while (NULL != root)
        {
            retArr[(*returnSize)++] = root->val;
            stack[++top] = root;
            root = root->left;
        }
        root = stack[top--];
        root = root->right;
    }
    return retArr;
}
// @lc code=end
