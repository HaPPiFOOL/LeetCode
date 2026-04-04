/*
 * @lc app=leetcode.cn id=21 lang=c
 *
 * [21] 合并两个有序链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *mergeTwoLists(struct ListNode *list1, struct ListNode *list2)
{
    // 直接修改原链表的指针来合并。
    struct ListNode *preHead = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *prev = preHead;
    while (list1 != NULL && list2 != NULL)
    {
        if (list1->val < list2->val)
        {
            prev->next = list1;
            list1 = list1->next;
        }
        else
        {
            prev->next = list2;
            list2 = list2->next;
        }
        prev = prev->next;
    }
    if (list1 != NULL)
        prev->next = list1;
    else
        prev->next = list2;
    return preHead->next;
}
// @lc code=end
