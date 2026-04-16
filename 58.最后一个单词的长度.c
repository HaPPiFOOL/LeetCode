/*
 * @lc app=leetcode.cn id=58 lang=c
 *
 * [58] 最后一个单词的长度
 */

// @lc code=start
int lengthOfLastWord(char *s)
{
    // 从尾部开始遍历，先跳过末尾的空格，然后统计最后一个单词的长度
    int index = strlen(s) - 1;
    int length = 0;
    while (index >= 0 && s[index] == ' ')
    {
        index--;
    }
    while (index >= 0 && s[index] != ' ')
    {
        length++;
        index--;
    }
    return length;
}
// @lc code=end
