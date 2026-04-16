/*
 * @lc app=leetcode.cn id=35 lang=c
 *
 * [35] 搜索插入位置
 */

// @lc code=start
int searchInsert(int *nums, int numsSize, int target)
{
    int left = 0;
    int right = numsSize - 1;
    int mid = (left + right) / 2;

    while (left <= right)
    {
        if (nums[mid] > target)
        {
            right = mid - 1;
            mid = (left + right) / 2;
        }

        if (nums[mid] < target)
        {
            left = mid + 1;
            mid = (left + right) / 2;
        }

        if (nums[mid] == target)
        {
            return mid;
        }
    }
    return left;
}
// @lc code=end
