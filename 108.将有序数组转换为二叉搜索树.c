/*
 * @lc app=leetcode.cn id=108 lang=c
 *
 * [108] 将有序数组转换为二叉搜索树
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
struct TreeNode *toTree(int *nums, int left, int right)
{
    // 本质是二分查找
    if (left > right)
        return NULL;

    int mid = (left + right) / 2;
    // 0 1 2 3 4
    struct TreeNode *node = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    node->val = nums[mid];
    node->left = toTree(nums, left, mid - 1);
    node->right = toTree(nums, mid + 1, right);
    return node;
}

struct TreeNode *sortedArrayToBST(int *nums, int numsSize)
{
    return toTree(nums, 0, numsSize - 1);
}
// @lc code=end
