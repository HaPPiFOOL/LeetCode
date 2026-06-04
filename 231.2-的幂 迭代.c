/*
 * @lc app=leetcode.cn id=231 lang=c
 *
 * [231] 2 的幂
 */

// @lc code=start
//
// n = 2 x 2 x 2 x ... x 2
// n % 2 一定为 0
// (n / 2) % 2 也一定为 0
//
bool isPowerOfTwo(int n)
{
    if (n <= 0)
    {
        return false;
    }

    while (n % 2 == 0)
    {
        n = n / 2;
    }

    return 1 == n;
}
// @lc code=end
