/*
 * @lc app=leetcode.cn id=111 lang=c
 *
 * [111] 二叉树的最小深度
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
int minDepth(struct TreeNode *root)
{
    if (root == NULL)
        return 0;

    struct TreeNode *queue[100000];
    int front = 0;
    int rear = 0;
    queue[rear++] = root;

    int minLevel = 0;
    while (front != rear)
    {
        minLevel++;
        int levelSize = rear - front;

        for (int i = 0; i < levelSize; i++)
        {
            struct TreeNode *node = queue[front++];

            if (node->left != NULL)
                queue[rear++] = node->left;

            if (node->right != NULL)
                queue[rear++] = node->right;

            if (node->left == NULL && node->right == NULL)
            {
                rear = front;
                break;
            }
        }
    }
    return minLevel;
}
// @lc code=end
