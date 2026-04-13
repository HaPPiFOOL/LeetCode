/*
 * @lc app=leetcode.cn id=27 lang=c
 *
 * [27] 移除元素
 */

// @lc code=start
int removeElement(int *nums, int numsSize, int val)
{
    // val = 2
    // [1,2,2,2,5,6,7,8,9]
    //    s       f
    // [1,6,2,2,5,6,7,8,9]
    //      s       f
    // 快指针向后遍历，指向不等于val的元素时
    // 将快指针指向的元素复制到慢指针位置后慢指针向前移动
    int slow = 0;
    for (int fast = 0; fast < numsSize; fast++)
    {
        if (nums[fast] != val)
        {
            nums[slow] = nums[fast];
            slow++;
        }
    }
    return slow;
}
// @lc code=end
