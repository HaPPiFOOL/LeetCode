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

int missingNumber(int *nums, int numsSize)
{
    int i = 0;
    while (i < numsSize)
    {
        if (nums[i] == numsSize)
        {
            i++;
            continue;
        }

        if (i != nums[i])
        {
            swap(&nums[nums[i]], &nums[i]);
        }
        else if (i == nums[i])
        {
            i++;
        }
    }

    for (int i = 0; i < numsSize; i++)
    {
        if (nums[i] == numsSize)
        {
            return i;
        }
    }

    return numsSize;
}
// @lc code=end
