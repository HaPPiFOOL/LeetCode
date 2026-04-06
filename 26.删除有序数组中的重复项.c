/*
 * @lc app=leetcode.cn id=26 lang=c
 *
 * [26] 删除有序数组中的重复项
 */

// @lc code=start
int removeDuplicates(int *nums, int numsSize)
{
    // 1, 1, 1, 1, 2, 3, 4
    // i           j
    // 1, 2, 1, 1, 2, 3, 4
    //    i           j
    // 一个指针指向不重复的最后一个元素，另一个指针向后遍历，如果不重复就把这个元素放到第一个指针的下一个位置
    int i = 0;
    int j = 1;
    while (j < numsSize)
    {
        if (nums[i] != nums[j])
        {
            nums[i + 1] = nums[j];
            i++;
        }
        j++;
    }
    return i + 1;
}
// @lc code=end
