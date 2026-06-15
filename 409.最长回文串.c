/*
 * @lc app=leetcode.cn id=409 lang=c
 *
 * [409] 最长回文串
 */

// @lc code=start
struct HashTable
{
    char key;
    int val;
    UT_hash_handle hh;
};

int longestPalindrome(char *s)
{
    struct HashTable *table = NULL;
    for (int i = 0; i < strlen(s); i++)
    {
        struct HashTable *item = NULL;
        HASH_FIND(hh, table, &s[i], sizeof(char), item);
        if (NULL == item)
        {
            item = malloc(sizeof(*item));
            item->key = s[i];
            item->val = 1;
            HASH_ADD(hh, table, key, sizeof(char), item);
            continue;
        }
        item->val += 1;
    }

    int hasOdd = 0;
    int total = 0;
    struct HashTable *item = NULL;
    struct HashTable *temp = NULL;
    HASH_ITER(hh, table, item, temp)
    {
        if (0 == item->val % 2)
        {
            total += item->val;
        }
        else if (1 == item->val % 2)
        {
            total += item->val - 1;
            hasOdd = 1;
        }
    }

    return total + hasOdd;
}
// @lc code=end
