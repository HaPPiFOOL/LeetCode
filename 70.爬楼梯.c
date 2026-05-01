/*
 * @lc app=leetcode.cn id=70 lang=c
 *
 * [70] 爬楼梯
 */

// @lc code=start
//                f(4)
//              /      \
//           f(3)      f(2)
//         /    \    /    \
//      f(2)   f(1) f(1)  f(0)
//     /    \
//  f(1)   f(0)
// 假设你要爬到第 n 阶，站在楼顶往下看，你最后一次动作只有两种情况：
//  1.从第 n-1 阶跨了 1 步上来的。
//  2.从第 n-2 阶跨了 2 步上来的。
// 到达第 n 阶的总方法数，就是把到达第 n-1 阶的方法和到达第 n-2 阶的方法加起来。
// f(1) = 1
// f(2) = 2
// f(3) = f(2) + f(1)
// f(n) = f(n-1) + f(n-2)
int climbStairs(int n)
{
    if (n == 1)
        return 1;

    if (n == 2)
        return 2;

    int f_n = 0;
    int f_1 = 1;
    int f_2 = 2;
    for (int i = 3; i <= n; i++)
    {
        f_n = f_1 + f_2;
        f_1 = f_2;
        f_2 = f_n;
    }
    return f_n;
}
// @lc code=end
