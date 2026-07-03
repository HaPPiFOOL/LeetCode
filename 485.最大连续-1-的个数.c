/*
 * @lc app=leetcode.cn id=485 lang=c
 *
 * [485] 最大连续 1 的个数
 */

// @lc code=start
int findMaxConsecutiveOnes(int *nums, int numsSize)
{
    int count = 0;
    int maxCount = 0;
    for (int i = 0; i < numsSize; i++)
    {
        if (0 == nums[i])
        {
            maxCount = maxCount > count ? maxCount : count;
            count = 0;
        }
        if (1 == nums[i])
        {
            count++;
        }
    }
    maxCount = maxCount > count ? maxCount : count;
    return maxCount;
}
// @lc code=end
