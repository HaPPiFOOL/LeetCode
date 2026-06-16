/*
 * @lc app=leetcode.cn id=415 lang=c
 *
 * [415] 字符串相加
 */

// @lc code=start
char *addStrings(char *num1, char *num2)
{
    // 全部对齐
    int len1 = strlen(num1);
    int len2 = strlen(num2);
    int retMaxLen = len1 > len2 ? len1 + 1 : len2 + 1;
    char *n1 = malloc(sizeof(char) * (retMaxLen + 1));
    char *n2 = malloc(sizeof(char) * (retMaxLen + 1));
    char *ret = malloc(sizeof(char) * (retMaxLen + 1));
    ret[retMaxLen] = '\0';

    for (int i = 0; i < retMaxLen; i++)
    {
        n1[i] = '0';
        n2[i] = '0';
    }

    memcpy(n1 + (retMaxLen - len1), num1, len1);
    memcpy(n2 + (retMaxLen - len2), num2, len2);

    int carry = 0;
    for (int i = retMaxLen - 1; i >= 0; i--)
    {
        int x = n1[i] - '0';
        int y = n2[i] - '0';
        int sum = x + y + carry;
        ret[i] = (sum % 10) + '0';
        carry = sum / 10;
    }

    return '0' == ret[0] ? ret + 1 : ret;
}
// @lc code=end
