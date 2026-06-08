/*
 * @lc app=leetcode.cn id=338 lang=c
 *
 * [338] 比特位计数
 */

// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *countBits(int n, int *returnSize)
{
    *returnSize = n + 1;
    int *bitsCount = malloc(sizeof(int) * (n + 1));
    bitsCount[0] = 0;
    for (int i = 1; i < n + 1; i++)
    {
        if (0 == i % 2)
        {
            bitsCount[i] = bitsCount[i / 2];
        }
        else if (1 == i % 2)
        {
            bitsCount[i] = bitsCount[i - 1] + 1;
        }
    }
    return bitsCount;
}
// @lc code=end
