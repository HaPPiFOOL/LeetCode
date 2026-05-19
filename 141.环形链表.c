/*
 * @lc app=leetcode.cn id=141 lang=c
 *
 * [141] 环形链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head)
{
    if (NULL == head || NULL == head->next)
        return false;

    struct ListNode *slow = head;
    struct ListNode *fast = head->next;

    /**
     * slow 指针速度为 1
     * fast 指针速度为 2 
     * 相对速度为 1
     * 因此距离是连续递减的（...3, 2, 1, 0），
     * 绝对不会跳过 0
     * 所以它们一定会在距离为 0 的那一个时刻相遇。
     */
    while (slow != fast)
    {
        if (NULL == fast || NULL == fast->next)
        {
            return false;
        }

        slow = slow->next;
        fast = fast->next->next;
    };

    return true;
}
// @lc code=end
