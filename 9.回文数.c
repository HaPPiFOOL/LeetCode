/*
 * @lc app=leetcode.cn id=9 lang=c
 *
 * [9] 回文数
 */

// @lc code=start
bool isPalindrome(int x)
{
    if (x < 0)
        return false;
    int t = x;            // x为32位整型
    long int reverse = 0; // 使用64位整型防止反转后溢出
    while (t)
    {
        reverse = reverse * 10 + t % 10; // 利用模运算取数字的低位
        t = t / 10;                      // 利用除法运算去掉数字的低位
    }
    return reverse == x ? true : false;
}
// @lc code=end
