/*
 * @lc app=leetcode.cn id=349 lang=c
 *
 * [349] 两个数组的交集
 */

// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
struct HashTable
{
    int key;
    UT_hash_handle hh;
};

int *intersection(int *nums1, int nums1Size, int *nums2, int nums2Size, int *returnSize)
{
    struct HashTable *table = NULL;

    // 将元素不重复的添加至哈希表
    for (int i = 0; i < nums1Size; i++)
    {
        struct HashTable *item = NULL;
        HASH_FIND(hh, table, &nums1[i], sizeof(int), item);
        if (NULL == item)
        {
            item = malloc(sizeof(*item));
            item->key = nums1[i];
            HASH_ADD(hh, table, key, sizeof(int), item);
        }
    }

    int hashcount = HASH_COUNT(table);
    int count = hashcount < nums2Size ? hashcount : nums2Size;
    int *ret = malloc(sizeof(int) * count);
    *returnSize = 0;

    // 如果在哈希表中找到该元素，添加到返回数组，并在哈希表中删除该元素
    for (int i = 0; i < nums2Size; i++)
    {
        struct HashTable *item = NULL;
        HASH_FIND(hh, table, &nums2[i], sizeof(int), item);
        if (NULL != item)
        {
            ret[(*returnSize)++] = item->key;
            HASH_DEL(table, item);
        }
    }

    return ret;
}
// @lc code=end
