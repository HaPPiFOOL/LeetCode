/*
 * @lc app=leetcode.cn id=268 lang=c
 *
 * [268] 丢失的数字
 */

// @lc code=start
int missingNumber(int *nums, int numsSize)
{
    int n = (1 + numsSize) * numsSize / 2;

    int sum = 0;
    for (int i = 0; i < numsSize; i++)
    {
        sum += nums[i];
    }

    return n - sum;
}
// @lc code=end
