/*
 * @lc app=leetcode.cn id=191 lang=c
 *
 * [191] 位1的个数
 */

// @lc code=start
int hammingWeight(int n)
{
    int mask = 0x00000001;
    int weight = 0;
    while (0 != n)
    {
        if (n & mask)
        {
            weight++;
        }
        n /= 2;
    }
    return weight;
}
// @lc code=end
