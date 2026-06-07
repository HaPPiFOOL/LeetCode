/*
 * @lc app=leetcode.cn id=283 lang=c
 *
 * [283] 移动零
 */

// @lc code=start
void moveZeroes(int *nums, int numsSize)
{
    int slow = 0;

    // fast 只需向后遍历
    for (int fast = 0; fast < numsSize; fast++)
    {
        // 找到不为 0 的数
        if (0 != nums[fast])
        {
            nums[slow] = nums[fast];
            slow++;
        }
    }

    while (slow < numsSize)
    {
        nums[slow] = 0;
        slow++;
    }
}
// @lc code=end
