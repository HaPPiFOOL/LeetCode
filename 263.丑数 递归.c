/*
 * @lc app=leetcode.cn id=263 lang=c
 *
 * [263] 丑数
 */

// @lc code=start
//
// U = 2^a * 3^b * 5^c
//
bool isUgly(int n)
{
    if (n <= 0)
        return false;

    if (n == n / 2 * 2)
        return isUgly(n / 2);
    if (n == n / 3 * 3)
        return isUgly(n / 3);
    if (n == n / 5 * 5)
        return isUgly(n / 5);

    return 1 == n;
}
// @lc code=end
