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
        return false;

    if (1 == n)
        return true;

    return 0 == (n % 3) && isPowerOfThree(n / 3);
}
// @lc code=end
