/*
 * @lc app=leetcode.cn id=401 lang=c
 *
 * [401] 二进制手表
 */

// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int bitsCount(int h)
{
    int count = 0;
    unsigned int mask = 1;
    for (int i = 0; i < 32; i++)
    {
        if (0 != (h & mask))
        {
            count++;
        }
        mask = mask << 1;
    }
    return count;
}

char **readBinaryWatch(int turnedOn, int *returnSize)
{
    char **ans = malloc(sizeof(*ans) * 12 * 60);
    *returnSize = 0;

    for (int h = 0; h < 12; h++)
    {
        for (int m = 0; m < 60; m++)
        {
            if (turnedOn == bitsCount(h) + bitsCount(m))
            {
                char *temp = malloc(sizeof(char) * 6);
                sprintf(temp, "%d:%02d", h, m);
                ans[(*returnSize)++] = temp;
            }
        }
    }

    return ans;
}
// @lc code=end
