/*
 * @lc app=leetcode.cn id=257 lang=c
 *
 * [257] 二叉树的所有路径
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
void constructPaths(struct TreeNode *node, char **pathArr, int *index, int *path, int length)
{
    // 边界条件
    if (node == NULL)
        return;

    // 保存路径
    path[length++] = node->val;

    // 边界条件：处理该叶节点叶子节点，并把它们变成字符串存进 pathArr
    if (NULL == node->left && NULL == node->right)
    {
        int offset = 0;
        char *buffer = (char *)malloc(sizeof(char) * 300);

        offset = sprintf(buffer + offset, "%d", path[0]);
        for (int i = 1; i < length; i++)
        {
            offset += sprintf(buffer + offset, "->%d", path[i]);
        }

        pathArr[(*index)++] = buffer;
        return;
    }

    // 相信它会处理左子树里的所有叶子节点，并把它们变成字符串存进 pathArr
    constructPaths(node->left, pathArr, index, path, length);
    // 相信它会处理右子树里的所有叶子节点，并把它们变成字符串存进 pathArr
    constructPaths(node->right, pathArr, index, path, length);

    return;
}

char **binaryTreePaths(struct TreeNode *root, int *returnSize)
{
    *returnSize = 0;
    int path[100];
    int lengh = 0;
    char **pathArr = (char **)malloc(sizeof(char *) * 100);

    constructPaths(root, pathArr, returnSize, path, lengh);

    return pathArr;
}
// @lc code=end
