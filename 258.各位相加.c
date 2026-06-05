/*
 * @lc app=leetcode.cn id=258 lang=c
 *
 * [258] 各位相加
 */

// @lc code=start
int addbits(int num)
{
    if (0 == num)
        return 0;

    return (num % 10) + addbits(num / 10);
}

int addDigits(int num)
{
    int x = num;
    while (x > 9)
        x = addbits(x);

    return x;
}
// @lc code=end
