/*
 * @lc app=leetcode.cn id=231 lang=c
 *
 * [231] 2 的幂
 */

// @lc code=start
//
// 对于一个整数n，如果它是2的幂，那么它的二进制表示中只有一位是1，其他位都是0。
// 因此n&(n-1)的结果应该是0，且n必须大于0。
//
bool isPowerOfTwo(int n)
{
    if (n <= 0)
        return false;
    if (n == 1)
        return true;

    // 如果是奇数，直接判死刑；如果是偶数，继续查它“祖宗八代”
    return (n % 2 == 0) && isPowerOfTwo(n / 2);
}
// @lc code=end
