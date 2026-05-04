/*
 * @lc app=leetcode.cn id=50 lang=c
 *
 * [50] Pow(x, n)
 */
//
// 负数的绝对值比正数大 1。
// 如果你直接在 myPow 里面对 int n 取反（即 -n）：
// 当 n = -2,147,483,648 时，
// 它的相反数应该是 2,147,483,648$。
// 但是 int 类型能表示的最大正数只有 2,147,483,647。
//
// @lc code=starm.
//
// (x^5)^2 * x     (x^2)^2 * x     (x^1)^2     x^0 * x       x^0
//     11       ->      5       ->     2     ->   1       ->  0
//   (y)^2 * x  <-   (y)^2 * x  <-     y^2   <-   y * x   <-  y = 1
//
double quicPow(double x, long long n)
{
    if (n == 0)
        return 1;
    // y = x^n
    double y = quicPow(x, n / 2);
    return n % 2 == 0 ? y * y : y * y * x;
}

double myPow(double x, int n)
{
    long long N = n;
    return N > 0 ? quicPow(x, N) : 1 / quicPow(x, -N);
}
// @lc code=end
