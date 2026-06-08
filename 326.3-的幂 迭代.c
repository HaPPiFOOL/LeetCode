/*
 * @lc app=leetcode.cn id=326 lang=c
 *
 * [326] 3 的幂
 */

// @lc code=start
// n = 3 * 3 * ... * 3
bool isPowerOfThree(int n)
{
    if (0 == n)
        return n;

    while (0 == (n % 3))
        n /= 3;

    return 1 == n;
}
// @lc code=end
