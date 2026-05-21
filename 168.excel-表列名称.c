/*
 * @lc app=leetcode.cn id=168 lang=c
 *
 * [168] Excel 表列名称
 */

// @lc code=start
char *convertToTitle(int columnNumber)
{
    // 26进制
    // number = ... + c·26 ^ 1 + c·26^0
    char temp[10];
    int len = 0;
    while (columnNumber)
    {
        // 将最低位的范围由 1~26 转换为 0~25 的 26 进制
        columnNumber = columnNumber - 1;
        temp[len++] = 'A' + columnNumber % 26;
        columnNumber = columnNumber / 26;
    }

    char *ret = (char *)malloc(sizeof(char) * (len + 1));
    for (int i = 0; i < len; i++)
    {
        ret[i] = temp[len - 1 - i];
    }
    ret[len] = '\0';
    return ret;
}
// @lc code=end
