/*
 * @lc app=leetcode.cn id=50 lang=c
 *
 * [50] Pow(x, n)
 */
// @lc code=starm.
//
// file:///Users/sunny/Library/Mobile%20Documents/iCloud~md~obsidian/Documents/My%20Note/算法%20快速幂%20迭代.md
// 
double myPow(double x, int n)
{
    long long N = n;
    if (N < 0)
    {
        x = 1 / x;
        N = -N;
    }

    double res = 1;
    while (N > 0)
    {
        if (N & 1)
            res = res * x;
        x = x * x;
        N = N >> 1;
    }
    return res;
}
// @lc code=end
