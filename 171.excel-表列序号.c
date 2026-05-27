/*
 * @lc app=leetcode.cn id=171 lang=c
 *
 * [171] Excel 表列序号
 */

// @lc code=start
int titleToNumber(char *columnTitle)
{
    // number = a_n * 26^n + ... + a_0 * 26^0
    int length = strlen(columnTitle);
    int n = length - 1;
    int sum = 0;
    long base = 1;
    for (int i = n; i >= 0; i--)
    {
        sum = sum + (columnTitle[i] - 'A' + 1) * base;
        base = base * 26;
    }
    return sum;
}
// @lc code=end
