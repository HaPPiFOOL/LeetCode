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

    while (0 == n % 2)
        n /= 2;
    while (0 == n % 3)
        n /= 3;
    while (0 == n % 5)
        n /= 5;

    return 1 == n;
}
// @lc code=end
