/*
 * @lc app=leetcode.cn id=104 lang=c
 *
 * [104] 二叉树的最大深度
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
int maxDepth(struct TreeNode *root)
{
    if (root == NULL)
        return 0;

    struct TreeNode *queue[10001]; // 队列
    int front = 0, rear = 0;       // 队首，指向队首元素；队尾，指向队尾元素后一个位置
    int deepth = 0;                // 层序遍历深度

    // 提前将root入队
    queue[rear++] = root;

    while (front != rear)
    {
        int levelSize = rear - front; // 该层节点总数

        for (int i = 0; i < levelSize; i++)
        {
            // 将该层节点出队
            struct TreeNode *node = queue[front++];

            // 将该层节点的所有左右孩子入队
            if (node->left)
                queue[rear++] = node->left;
            if (node->right)
                queue[rear++] = node->right;
        }
        deepth++;
    }
    return deepth;
}
// @lc code=end
