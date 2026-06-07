/*
 * @lc app=leetcode.cn id=290 lang=c
 *
 * [290] 单词规律
 */

// @lc code=start
/**
 * key -> val 的映射关系为一一映射
 */
struct HashTableP_S
{
    char key;
    char *val;
    UT_hash_handle hh;
};

struct HashTableS_P
{
    char *key;
    char val;
    UT_hash_handle hh;
};

bool wordPattern(char *pattern, char *s)
{
    // p 中字母个数
    int p_count = strlen(pattern);
    // s 中单词个数
    int s_count = 0;

    char **strArr = (char **)malloc(sizeof(char *) * 300);

    int slow = 0;
    for (int fast = 0; fast <= strlen(s); fast++)
    {
        if (' ' == s[fast] || '\0' == s[fast])
        {
            int wordLen = fast - slow;
            strArr[s_count] = (char *)malloc(sizeof(char) * (wordLen + 1));
            strncpy(strArr[s_count], s + slow, wordLen);
            strArr[s_count][wordLen] = '\0';

            slow = fast + 1;
            s_count = s_count + 1;
        }
    }

    if (p_count != s_count)
    {
        return false;
    }

    struct HashTableP_S *P_S = NULL;
    struct HashTableS_P *S_P = NULL;

    for (int i = 0; i < p_count; i++)
    {
        struct HashTableP_S *p_s = NULL;
        struct HashTableS_P *s_p = NULL;

        // 如果缺少 P->S 的映射，添加该映射
        HASH_FIND(hh, P_S, &pattern[i], sizeof(char), p_s);
        if (NULL == p_s)
        {
            p_s = (struct HashTableP_S *)malloc(sizeof(struct HashTableP_S));
            p_s->key = pattern[i];
            p_s->val = strArr[i];
            HASH_ADD(hh, P_S, key, sizeof(char), p_s);
        }

        // 如果缺少 S->P 的映射，添加该映射
        HASH_FIND(hh, S_P, strArr[i], strlen(strArr[i]), s_p);
        if (NULL == s_p)
        {
            s_p = (struct HashTableS_P *)malloc(sizeof(struct HashTableS_P));
            s_p->key = strArr[i];
            s_p->val = pattern[i];
            HASH_ADD_KEYPTR(hh, S_P, s_p->key, strlen(s_p->key), s_p);
        }

        // 添加的映射一定会成对出现
        if (p_s->key != s_p->val || s_p->key != p_s->val)
        {
            return false;
        }
    }
    return true;
}
// @lc code=end
