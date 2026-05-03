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
void inorder(struct TreeNode *root, int *retArr, int *index)
{
    if (root == NULL)
        return;
    inorder(root->left, retArr, index);
    retArr[(*index)++] = root->val;
    inorder(root->right, retArr, index);
}

int *inorderTraversal(struct TreeNode *root, int *returnSize)
{
    int i = 0;
    int *retArr = (int *)malloc(sizeof(int) * 101);
    inorder(root, retArr, &i);
    *returnSize = i;
    return retArr;
}
// @lc code=end
