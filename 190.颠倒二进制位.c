/*
 * @lc app=leetcode.cn id=190 lang=c
 *
 * [190] 颠倒二进制位
 */

// @lc code=start
int reverseBits(int n)
{
    unsigned int mask1 = 0x80000000;
    unsigned int mask2 = 0x00000001;
    int reversed = 0;
    for (int i = 0; i < 32; i++)
    {
        if (mask1 & n)
            reversed += mask2;
        mask1 = mask1 >> 1;
        mask2 = mask2 << 1;
    }
    return reversed;
}
// @lc code=end
