/*
 * @lc app=leetcode.cn id=206 lang=c
 *
 * [206] 反转链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode *reverseList(struct ListNode *head)
{
    // 1.边界条件
    if (NULL == head || NULL == head->next)
        return head;

    // 2.你要相信递归函数已经反转了head->next之后的节点，并返回更新后的首节点
    struct ListNode *node = reverseList(head->next);

    // 3.根据正常工作的递归函数处理剩下的部分
    head->next->next = head;
    head->next = NULL;

    return node;
}
// @lc code=end
