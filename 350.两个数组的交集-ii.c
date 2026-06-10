/*
 * @lc app=leetcode.cn id=350 lang=c
 *
 * [350] 两个数组的交集 II
 */

// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
struct HashTable
{
    int key;
    int val;
    UT_hash_handle hh;
};

int *intersect(int *nums1, int nums1Size, int *nums2, int nums2Size, int *returnSize)
{
    struct HashTable *table1 = NULL;
    struct HashTable *table2 = NULL;

    for (int i = 0; i < nums1Size; i++)
    {
        struct HashTable *item = NULL;
        HASH_FIND(hh, table1, &nums1[i], sizeof(int), item);
        if (NULL == item)
        {
            item = malloc(sizeof(*item));
            item->key = nums1[i];
            item->val = 1;
            HASH_ADD(hh, table1, key, sizeof(int), item);
        }
        else
        {
            item->val += 1;
        }
    }

    for (int i = 0; i < nums2Size; i++)
    {
        struct HashTable *item = NULL;
        HASH_FIND(hh, table2, &nums2[i], sizeof(int), item);
        if (NULL == item)
        {
            item = malloc(sizeof(*item));
            item->key = nums2[i];
            item->val = 1;
            HASH_ADD(hh, table2, key, sizeof(int), item);
        }
        else
        {
            item->val += 1;
        }
    }

    int *retNums = malloc(sizeof(int) * (nums1Size < nums2Size ? nums1Size : nums2Size));
    struct HashTable *e1, *temp;
    *returnSize = 0;
    HASH_ITER(hh, table1, e1, temp)
    {
        struct HashTable *e2 = NULL;
        HASH_FIND(hh, table2, &e1->key, sizeof(int), e2);
        if (NULL != e2)
        {
            int count = e1->val < e2->val ? e1->val : e2->val;
            for (int i = 0; i < count; i++)
            {
                retNums[(*returnSize)++] = e1->key;
            }
        }
    }

    return retNums;
}
// @lc code=end
