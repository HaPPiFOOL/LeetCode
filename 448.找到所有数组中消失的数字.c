/*
 * @lc app=leetcode.cn id=448 lang=c
 *
 * [448] 找到所有数组中消失的数字
 */

// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *findDisappearedNumbers(int *nums, int numsSize, int *returnSize)
{
    int *ret = malloc(sizeof(int) * (numsSize + 1));
    for (int i = 0; i < numsSize + 1; i++)
    {
        ret[i] = i;
    }

    for (int i = 0; i < numsSize; i++)
    {
        ret[nums[i]] = 0;
    }

    int slow = 0;
    for (int fast = 0; fast < numsSize + 1; fast++)
    {
        if (0 != ret[fast])
        {
            ret[slow] = ret[fast];
            slow++;
        }
    }
    *returnSize = slow;
    return ret;
}
// @lc code=end
