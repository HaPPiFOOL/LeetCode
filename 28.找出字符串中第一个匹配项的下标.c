/*
 * @lc app=leetcode.cn id=28 lang=c
 *
 * [28] 找出字符串中第一个匹配项的下标
 */

// @lc code=start
int strStr(char *haystack, char *needle)
{
    // 暴力匹配
    int m = strlen(needle);
    int n = strlen(haystack);
    for (int i = 0; i <= n - m; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (haystack[i + j] != needle[j])
            {
                break;
            }
            if (j == m - 1)
            {
                return i;
            }
        }
    }
    return -1;
}
// @lc code=end
