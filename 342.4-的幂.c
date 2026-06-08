/*
 * @lc app=leetcode.cn id=342 lang=c
 *
 * [342] 4的幂
 */

// @lc code=start
/**
 * n = 4^x = 2^x * 2^x
 * n 一定在偶数位
 */
bool isPowerOfFour(int n)
{
    if (n <= 0)
        return false;

    if (1 == n)
        return true;

    return 0 == (n & (n - 1)) && 0 == (n & 0xAAAAAAAA);
}
// @lc code=end
