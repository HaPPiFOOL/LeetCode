/*
 * @lc app=leetcode.cn id=434 lang=c
 *
 * [434] 字符串中的单词数
 */

// @lc code=start
int countSegments(char *s)
{
    int len = strlen(s);
    int count = 0;
    int inWord = 0;

    // 状态机
    for (int i = 0; i < len; i++)
    {
        if (' ' != s[i])
        {
            inWord = 1;
            continue;
        }
        else if (' ' == s[i])
        {
            if (1 == inWord)
            {
                inWord = 0;
                count++;
            }
        }
    }

    return 1 == inWord ? count + 1 : count;
}
// @lc code=end
