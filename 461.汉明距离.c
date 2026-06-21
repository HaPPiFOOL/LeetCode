/*
 * @lc app=leetcode.cn id=461 lang=c
 *
 * [461] 汉明距离
 */

// @lc code=start
int hammingDistance(int x, int y)
{
    int z = x ^ y;
    int count = 0;
    unsigned mask = 0x0000001;
    for (int i = 0; i < 32; i++)
    {
        count += (z & mask) ? 1 : 0;
        mask = mask << 1;
    }
    return count;
}
// @lc code=end
