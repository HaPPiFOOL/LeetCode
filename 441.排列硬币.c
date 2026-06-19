/*
 * @lc app=leetcode.cn id=441 lang=c
 *
 * [441] 排列硬币
 */

// @lc code=start
int arrangeCoins(int n)
{
    return (-1 + sqrt(1 + 8 * (long)n)) / 2;
}
// @lc code=end
