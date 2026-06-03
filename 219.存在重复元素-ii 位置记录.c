/*
 * @lc app=leetcode.cn id=219 lang=c
 *
 * [219] 存在重复元素 II
 */

// @lc code=start
struct HashTable
{
    int key;
    int val;
    UT_hash_handle hh;
};

bool containsNearbyDuplicate(int *nums, int numsSize, int k)
{
    struct HashTable *table = NULL;
    for (int i = 0; i < numsSize; i++)
    {
        struct HashTable *item = NULL;

        if (i > k)
        {
            HASH_FIND(hh, table, &nums[i - k - 1], sizeof(int), item);
            item->val -= 1;
            if (0 == item->val)
            {
                HASH_DEL(table, item);
            }
        }

        HASH_FIND(hh, table, &nums[i], sizeof(int), item);
        if (NULL == item)
        {
            item = (struct HashTable *)malloc(sizeof(struct HashTable));
            item->key = nums[i];
            item->val = 1;
            HASH_ADD(hh, table, key, sizeof(int), item);
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
