/*
 * @lc app=leetcode.cn id=160 lang=c
 *
 * [160] 相交链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB)
{
    int lenA = 0;
    int lenB = 0;

    for (struct ListNode *node = headA; NULL != node; node = node->next)
        lenA++; // m

    for (struct ListNode *node = headB; NULL != node; node = node->next)
        lenB++; // n

    int dif = lenA > lenB ? lenA - lenB : lenB - lenA;

    struct ListNode *pA = headA;
    struct ListNode *pB = headB;

    if (lenA > lenB)
    {
        while (dif)
        {
            pA = pA->next;
            dif--;
        }
    }
    else
    {
        while (dif)
        {
            pB = pB->next;
            dif--;
        }
    }

    while (NULL != pA)
    {
        if (pA == pB)
            return pA;

        pA = pA->next;
        pB = pB->next;
    }

    return NULL;
}
// @lc code=end
