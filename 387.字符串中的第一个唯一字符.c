/*
 * @lc app=leetcode.cn id=387 lang=c
 *
 * [387] 字符串中的第一个唯一字符
 */

// @lc code=start
int firstUniqChar(char *s)
{
    int HASH[128] = {0};

    int len = strlen(s);
    for (int i = 0; i < len; i++)
    {
        HASH[s[i]]++;
    }
    
    for (int i = 0; i < len; i++)
    {
        if (1 == HASH[s[i]])
            return i;
    }

    return -1;
}
// @lc code=end
