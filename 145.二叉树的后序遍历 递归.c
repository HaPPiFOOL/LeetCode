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
void postorder(struct TreeNode *node, int *retArr, int *index)
{
    if (NULL == node)
        return;

    postorder(node->left, retArr, index);
    postorder(node->right, retArr, index);
    retArr[(*index)++] = node->val;

    return;
}

int *postorderTraversal(struct TreeNode *root, int *returnSize)
{
    *returnSize = 0;
    int *retArr = (int *)malloc(sizeof(int) * 101);

    postorder(root, retArr, returnSize);

    return retArr;
}
// @lc code=end
