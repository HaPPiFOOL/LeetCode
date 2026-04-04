/*
 * @lc app=leetcode.cn id=14 lang=c
 *
 * [14] 最长公共前缀
 */

// @lc code=start
char *longestCommonPrefix(char **strs, int strsSize)
{
    if (strsSize == 0)
        return "";
    // 以第一个字符串为基准，逐个字符比较
    for (int i = 0; strs[0][i] != '\0'; i++)
    {
        char c = strs[0][i];
        for (int j = 1; j < strsSize; j++)
        {
            // 多个字符串纵向比较
            if (strs[j][i] != c)
            {
                // 以第一个字符串为基准，返回前i个字符
                return strndup(strs[0], i);
            }
        }
    }
    // 如果strsSize==1，则返回第一个字符串；
    return strs[0];
}
// @lc code=end
