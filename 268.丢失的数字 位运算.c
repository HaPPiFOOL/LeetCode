/*
 * @lc app=leetcode.cn id=268 lang=c
 *
 * [268] 丢失的数字
 */

// @lc code=start
//
// 异或的性质
//
int missingNumber(int *nums, int numsSize)
{
    int x = 0;

    for (int i = 1; i <= numsSize; i++)
    {
        x = i ^ x;
    }

    for (int i = 0; i < numsSize; i++)
    {
        x ^= nums[i];
    }

    return x;
}
// @lc code=end
