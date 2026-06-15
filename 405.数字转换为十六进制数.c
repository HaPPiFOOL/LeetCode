/*
 * @lc app=leetcode.cn id=405 lang=c
 *
 * [405] 数字转换为十六进制数
 */

// @lc code=start
char *toHex(int num)
{
    if (0 == num)
    {
        return "0";
    }

    char *hex = malloc(sizeof(char) * 9);
    hex[8] = '\0';

    unsigned int n = (unsigned int)num;
    for (int i = 0; i < 8; i++)
    {
        int temp = (n >> (4 * (7 - i))) & 0xF;

        if (temp < 10)
        {
            hex[i] = temp + '0';
        }
        else
        {
            hex[i] = temp - 10 + 'a';
        }
    }

    int i = 0;
    while ('0' == hex[i])
        i++;

    return &hex[i];
}
// @lc code=end
