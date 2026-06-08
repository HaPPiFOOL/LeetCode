/*
 * @lc app=leetcode.cn id=344 lang=c
 *
 * [344] 反转字符串
 */

// @lc code=start
void reverseString(char *s, int sSize)
{
    int count = sSize / 2;
    for (int i = 0; i < count; i++)
    {
        char temp = s[i];
        s[i] = s[sSize - i - 1];
        s[sSize - i - 1] = temp;
    }
}
// @lc code=end
