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

bool isPalindrome(struct ListNode *head)
{
    int vals[100000];
    int i = 0;
    int j = -1;

    while (NULL != head)
    {
        j++;
        vals[j] = head->val;
        head = head->next;
    }

    while (i < j)
    {
        if (vals[i] != vals[j])
        {
            return false;
        }
        i++, j--;
    }

    return true;
}
// @lc code=end
