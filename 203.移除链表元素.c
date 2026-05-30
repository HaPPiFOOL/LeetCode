/*
 * @lc app=leetcode.cn id=203 lang=c
 *
 * [203] 移除链表元素
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *removeElements(struct ListNode *head, int val)
{
    // struct ListNode *trash = NULL;

    while (NULL != head && head->val == val)
    {
        // trash = head;
        head = head->next;
        // free(trash);
    }

    struct ListNode *cur = head;

    while (NULL != cur && cur->next)
    {
        if (cur->next->val == val)
        {
            // trash = cur->next;
            cur->next = cur->next->next;
            // free(trash);
        }
        else
        {
            cur = cur->next;
        }
    }

    return head;
}
// @lc code=end
