/*
 * @lc app=leetcode.cn id=234 lang=c
 *
 * [234] 回文链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool recursive(struct ListNode *node, struct ListNode **pre)
{
    // 边界条件
    if (NULL == node)
        return true;

    // 相信递归函数的作用：node后面的节点是否满足回文性
    if (false == recursive(node->next, pre))
        return false;

    // 处理当前节点的回文性判断
    if ((*pre)->val != node->val)
        return false;

    (*pre) = (*pre)->next;

    return true;
}

bool isPalindrome(struct ListNode *head)
{
    return recursive(head, &head);
}
// @lc code=end
