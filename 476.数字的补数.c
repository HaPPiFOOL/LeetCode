/*
 * @lc app=leetcode.cn id=476 lang=c
 *
 * [476] 数字的补数
 */

// @lc code=start
int findComplement(int num)
{
    unsigned mask = 0x80000000;
    while (0 == (num & mask))
    {
        num = num | mask;
        mask = mask >> 1;
    }
    return ~num;
}
// @lc code=end
