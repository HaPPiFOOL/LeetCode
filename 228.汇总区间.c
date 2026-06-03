/*
 * @lc app=leetcode.cn id=228 lang=c
 *
 * [228] 汇总区间
 */

// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char **summaryRanges(int *nums, int numsSize, int *returnSize)
{
    char **ret = malloc(sizeof(char *) * numsSize);
    *returnSize = 0;

    int i = 0;
    while (i < numsSize)
    {
        // 连续区间起始位置
        int start = i;

        // 连续区间判断
        while (i + 1 < numsSize && nums[i + 1] == nums[i] + 1)
        {
            i++;
        }

        // 连续区间结束位置
        int end = i;

        char *str = malloc(sizeof(char) * 45);

        if (start == end)
            sprintf(str, "%d", nums[start]);
        else
            sprintf(str, "%d->%d", nums[start], nums[end]);

        ret[(*returnSize)++] = str;

        // 下一个连续区间的起始位置
        i++;
    }
    return ret;
}
// @lc code=end
