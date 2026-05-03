/*
 * @lc app=leetcode.cn id=101 lang=c
 *
 * [101] 对称二叉树
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
bool isSym(struct TreeNode *p, struct TreeNode *q)
{
    // 如果两个对应节点都为空，则它们相同
    if (p == NULL && q == NULL)
        return true;

    // 如果对应的两个节点中有一个为空，或者两个节点的节点值不同，则它们不相同
    if (p == NULL || q == NULL || p->val != q->val)
        return false;

    // 递归比较左子树和右子树
    return isSym(p->left, q->right) && isSym(p->right, q->left);
}

bool isSymmetric(struct TreeNode *root)
{
    return isSym(root->left, root->right);
}
// @lc code=end
