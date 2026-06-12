/*
 * @lc app=leetcode.cn id=389 lang=c
 *
 * [389] 找不同
 */

// @lc code=start
char findTheDifference(char *s, char *t)
{
    int HASH[128] = {0};

    int len1 = strlen(s);
    for (int i = 0; i < len1; i++)
    {
        HASH[s[i]]++;
    }

    int len2 = strlen(t);
    for (int i = 0; i < len2; i++)
    {
        HASH[t[i]]--;
        if (HASH[t[i]] < 0)
        {
            return t[i];
        }
    }

    return ' ';
}
// @lc code=end
