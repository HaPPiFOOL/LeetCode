/*
 * @lc app=leetcode.cn id=392 lang=c
 *
 * [392] 判断子序列
 */

// @lc code=start
bool isSubsequence(char *s, char *t)
{
    int len1 = strlen(s);
    int len2 = strlen(t);

    if (len1 > len2)
    {
        return false;
    }

    int p1 = 0;
    int p2 = 0;
    while (p1 < len1 && p2 < len2)
    {
        if (s[p1] == t[p2])
        {
            p1++;
        }
        p2++;
    }

    if (p1 == len1)
    {
        return true;
    }
    
    return false;
}
// @lc code=end
