/*
 * @lc app=leetcode.cn id=268 lang=c
 *
 * [268] 丢失的数字
 */

// @lc code=start
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

/**
 * 在区间[0,n]中，所有元素出现 至多一次
 * 且只有 一个元素 没有出现
 *
 * 如果没有出现的元素是 n
 *      除 n 之外的所有 元素值 均能对应其 索引下标
 * 如果没有出现的元素不是 n
 *      n 会出现在没有出现的 元素值 对应的 索引下标上
 */
int missingNumber(int *nums, int numsSize)
{
    int i = 0;
    while (i < numsSize)
    {
        // 如果当前位置的数正好为区间内的最大值，跳过交换
        if (nums[i] == numsSize)
        {
            i++;
            continue;
        }

        // 如果数组中的 元素值 与 索引下标 不相等
        if (i != nums[i])
        {
            // 将 元素值 交换到，对应的 索引下标 上
            swap(&nums[nums[i]], &nums[i]);
        }
        // 如果数组中的 元素值 与 索引下标 相等
        else if (i == nums[i])
        {
            // 跳过
            i++;
        }
    }

    
    for (int i = 0; i < numsSize; i++)
    {
        // 元素 n 出现
        if (nums[i] == numsSize)
        {
            return i;
        }
    }

    // 除 n 之外的所有元素均能出现
    // 没有出现的元素是 n
    return numsSize;
}
// @lc code=end
