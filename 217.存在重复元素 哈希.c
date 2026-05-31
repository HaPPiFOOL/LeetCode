/*
 * @lc app=leetcode.cn id=217 lang=c
 *
 * [217] 存在重复元素
 */

// @lc code=start
struct HashTable
{
    int key;
    int val;
    UT_hash_handle hh;
};

bool containsDuplicate(int *nums, int numsSize)
{
    struct HashTable *Count = NULL;
    for (int i = 0; i < numsSize; i++)
    {
        struct HashTable *item = NULL;

        HASH_FIND(hh, Count, &nums[i], sizeof(int), item);

        if (NULL == item)
        {
            item = (struct HashTable *)malloc(sizeof(struct HashTable));
            item->key = nums[i];
            item->val = 1;
            HASH_ADD(hh, Count, key, sizeof(int), item);
        }
        else
        {
            item->val += 1;
            if (2 == item->val)
            {
                return true;
            }
        }
    }
    return false;
}
// @lc code=end
