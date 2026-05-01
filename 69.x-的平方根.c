/*
 * @lc app=leetcode.cn id=69 lang=c
 *
 * [69] x 的平方根
 */

// @lc code=start
int mySqrt(int n)
{
    // 牛顿迭代法
    // f(x) = x^2 - c
    // f'(x) = 2x
    // x_n+1 = x_n - f(x_n)/f'(x_n)
    // 对于该函数f(x),迭代的初始位置不为0即可
    if (n == 0)
        return 0;

    double c = n;
    double x = 1;

    while (true)
    {
        double x_n = x - (x * x - c) / (2 * x);
        if (fabs(x - x_n) < 1e-8)
            break;
        x = x_n;
    }
    return x;
}
// @lc code=end
