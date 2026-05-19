/*
 * @lc app=leetcode.cn id=136 lang=c
 *
 * [136] 只出现一次的数字
 */

// @lc code=start
int singleNumber(int *nums, int numsSize)
{
    int num = 0;
    
    for (int i = 0; i < numsSize; i++)
        num = num ^ nums[i];

    return num;
}
// @lc code=end
