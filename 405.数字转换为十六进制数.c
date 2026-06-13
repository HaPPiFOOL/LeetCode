/*
 * @lc app=leetcode.cn id=405 lang=c
 *
 * [405] 数字转换为十六进制数
 */

// @lc code=start
char *toHex(int num)
{
    char *hex = malloc(sizeof(char) * 9);
    if (0 == num)
    {
        hex[0] = '0';
        hex[1] = '\0';
        return hex;
    }

    unsigned int n = (unsigned int)num;

    int count = 0;
    bool started = false;

    for (int i = 0; i < 8; i++)
    {
        unsigned int temp = (n >> (4 * (7 - i))) & 0xF;

        if (!started && temp == 0)
        {
            continue;
        }

        started = true;

        if (temp < 10)
        {
            hex[count++] = temp + '0';
        }
        else
        {
            hex[count++] = temp - 10 + 'a';
        }
    }

    hex[count] = '\0';

    return hex;
}
// @lc code=end
