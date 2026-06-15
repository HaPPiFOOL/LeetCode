/*
 * @lc app=leetcode.cn id=412 lang=c
 *
 * [412] Fizz Buzz
 */

// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char **fizzBuzz(int n, int *returnSize)
{
    *returnSize = 0;
    char **ret = malloc(sizeof(*ret) * n);

    for (int i = 1; i <= n; i++)
    {
        if (0 == i % 3 && 0 == i % 5)
        {
            ret[(*returnSize)++] = "FizzBuzz";
        }
        else if (0 == i % 3)
        {
            ret[(*returnSize)++] = "Fizz";
        }
        else if (0 == i % 5)
        {
            ret[(*returnSize)++] = "Buzz";
        }
        else
        {
            char *temp = malloc(sizeof(*temp) * 6);
            sprintf(temp, "%d", i);
            ret[(*returnSize)++] = temp;
        }
    }
    return ret;
}
// @lc code=end
