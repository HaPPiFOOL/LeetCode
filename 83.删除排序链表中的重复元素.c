/*
 * @lc app=leetcode.cn id=83 lang=c
 *
 * [83] 删除排序链表中的重复元素
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *deleteDuplicates(struct ListNode *head)
{
    // cru 遍历指针
    struct ListNode *cru = head;
    // temp 暂存指针
    struct ListNode *temp = cru;
    // 下一个元素值等于当前元素->删除，不等于当前元素->移动指针
    while (cru != NULL && cru->next != NULL)
    {
        if (cru->val == cru->next->val)
        {
            temp = cru->next;
            cru->next = temp->next;
            free(temp);
        }
        else if (cru->val != cru->next->val)
        {
            cru = cru->next;
        }
    }
    return head;
}
// @lc code=end
