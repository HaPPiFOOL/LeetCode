/*
 * @lc app=leetcode.cn id=242 lang=c
 *
 * [242] 有效的字母异位词
 */

// @lc code=start
struct HashTable
{
    char key;
    int val;
    UT_hash_handle hh;
};

bool isAnagram(char *s, char *t)
{
    int len_s = strlen(s);
    int len_t = strlen(t);

    if (len_s != len_t)
    {
        return false;
    }

    struct HashTable *table = NULL;

    for (int i = 0; i < len_s; i++)
    {
        struct HashTable *item = NULL;
        HASH_FIND(hh, table, &s[i], sizeof(char), item);
        if (NULL == item)
        {
            item = (struct HashTable *)malloc(sizeof(struct HashTable));
            item->key = s[i];
            item->val = 1;
            HASH_ADD(hh, table, key, sizeof(char), item);
            continue;
        }
        item->val++;
    }

    for (int i = 0; i < len_t; i++)
    {
        struct HashTable *item = NULL;
        
        HASH_FIND(hh, table, &t[i], sizeof(char), item);
        if (NULL == item)
        {
            return false;
        }

        item->val--;
        if (0 == item->val)
        {
            HASH_DEL(table, item);
        }
    }

    return NULL == table;
}
// @lc code=end
