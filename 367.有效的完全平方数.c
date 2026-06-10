/*
 * @lc app=leetcode.cn id=367 lang=c
 *
 * [367] 有效的完全平方数
 */

// @lc code=start
bool isPerfectSquare(int num)
{
    if (num == 0)
        return 0;

    double c = num;
    double x = 1;

    while (true)
    {
        double x_n = x - (x * x - c) / (2 * x);
        if (fabs(x - x_n) < 1e-8)
            break;
        x = x_n;
    }
    return (int)x * (int)x == num;
}
// @lc code=end
