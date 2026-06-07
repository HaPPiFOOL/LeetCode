/*
 * @lc app=leetcode.cn id=205 lang=c
 *
 * [205] 同构字符串
 */

// @lc code=start
struct HashTable
{
    char key;
    char val;
    UT_hash_handle hh;
};

bool isIsomorphic(char *s, char *t)
{
    struct HashTable *S_T = NULL; // F: S -> T
    struct HashTable *T_S = NULL; // G: T -> S

    int len = strlen(s);

    for (int i = 0; i < len; i++)
    {
        // 映射关系
        struct HashTable *s_t = NULL;
        struct HashTable *t_s = NULL;

        HASH_FIND(hh, S_T, &s[i], sizeof(char), s_t);
        if (NULL == s_t)
        {
            s_t = (struct HashTable *)malloc(sizeof(struct HashTable));
            s_t->key = s[i];
            s_t->val = t[i];
            HASH_ADD(hh, S_T, key, sizeof(char), s_t);
        }

        HASH_FIND(hh, T_S, &t[i], sizeof(char), t_s);
        if (NULL == t_s)
        {
            t_s = (struct HashTable *)malloc(sizeof(struct HashTable));
            t_s->key = t[i];
            t_s->val = s[i];
            HASH_ADD(hh, T_S, key, sizeof(char), t_s);
        }

        if (s_t->key != t_s->val || t_s->key != s_t->val)
            return false;
    }

    return true;
}
// @lc code=end
