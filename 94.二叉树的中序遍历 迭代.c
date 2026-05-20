/*
 * @lc app=leetcode.cn id=94 lang=c
 *
 * [94] 二叉树的中序遍历
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
int *inorderTraversal(struct TreeNode *root, int *returnSize)
{
    // 栈
    int top = -1;
    struct TreeNode *stack[101];
    // 结果
    int *retArr = (int *)malloc(sizeof(int) * 101);
    *returnSize = 0;

    while (root != NULL || top > -1)
    {
        while (root != NULL)
        {
            stack[++top] = root; // 不断将当前节点入栈
            root = root->left;   // 优先入栈左侧节点
        }
        root = stack[top--];              // 左侧节点为NULL，出栈
        retArr[(*returnSize)++] = root->val; // 记录出栈节点值
        root = root->right;               // 入栈出栈节点的右侧节点
    }
    return retArr;
}
// @lc code=end
