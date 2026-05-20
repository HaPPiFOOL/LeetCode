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
void preorder(struct TreeNode *node, int *arr, int *index)
{
    if (NULL == node)
        return;

    arr[(*index)++] = node->val;
    preorder(node->left, arr, index);
    preorder(node->right, arr, index);

    return;
}

int *preorderTraversal(struct TreeNode *root, int *returnSize)
{
    *returnSize = 0;
    int *arr = (int *)malloc(sizeof(int) * 101);

    preorder(root, arr, returnSize);
    
    return arr;
}
// @lc code=end
