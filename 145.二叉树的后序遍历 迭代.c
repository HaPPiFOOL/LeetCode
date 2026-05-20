/*
 * @lc app=leetcode.cn id=145 lang=c
 *
 * [145] 二叉树的后序遍历
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
int *postorderTraversal(struct TreeNode *root, int *returnSize)
{
    // 栈
    int top = -1;
    struct TreeNode *stack[101];
    // 结果
    int *retArr = (int *)malloc(sizeof(int) * 101);
    *returnSize = 0;

    // 后续遍历左-右-根，是根-右-左遍历的逆序化！
    while (NULL != root || top > -1)
    {
        while (NULL != root)
        {
            retArr[(*returnSize)++] = root->val;
            stack[++top] = root;
            root = root->right;
        }
        root = stack[top--];
        root = root->left;
    }

    // 逆序化的到左-右-根
    int temp;
    int mid = (*returnSize) / 2;
    int end = (*returnSize) - 1;
    for (int i = 0; i < mid; i++)
    {
        temp = retArr[i];
        retArr[i] = retArr[end - i];
        retArr[end - i] = temp;
    }
    return retArr;
}
// @lc code=end
