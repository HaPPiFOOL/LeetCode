/*
 * @lc app=leetcode.cn id=219 lang=c
 *
 * [219] 存在重复元素 II
 */

// @lc code=start
struct HashTable
{
    int key;
    int last_index;
    UT_hash_handle hh;
};

bool containsNearbyDuplicate(int *nums, int numsSize, int k)
{
    struct HashTable *table = NULL;
    for (int i = 0; i < numsSize; i++)
    {
        struct HashTable *item = NULL;
        
        HASH_FIND(hh, table, &nums[i], sizeof(int), item);
        if (NULL == item)
        {
            item = (struct HashTable *)malloc(sizeof(struct HashTable));
            item->key = nums[i];
            item->last_index = i;
            HASH_ADD(hh, table, key, sizeof(int), item);
        }
        else
        {
            if (abs(item->last_index - i) <= k)
            {
                return true;
            }
            else
            {
                item->last_index = i;
            }
        }
    }
    return false;
}
// @lc code=end
