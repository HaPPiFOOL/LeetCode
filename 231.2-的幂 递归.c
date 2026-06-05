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

    if (1 == n)
    {
        return true;
    }

    // 相信递归函数能判断 n/2 及之后的数是否是 2 的幂
    return (n % 2 == 0) && isPowerOfTwo(n / 2);
}
// @lc code=end
