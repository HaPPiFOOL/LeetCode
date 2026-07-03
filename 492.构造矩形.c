/*
 * @lc app=leetcode.cn id=492 lang=c
 *
 * [492] 构造矩形
 */

// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *constructRectangle(int area, int *returnSize)
{
    int w = sqrt(area);
    int *ret = malloc(sizeof(int) * 2);
    while (w > 0)
    {
        if (0 == area % w)
        {
            ret[0] = area / w;
            ret[1] = w;
            break;
        }
        w--;
    }
    *returnSize = 2;
    return ret;
}
// @lc code=end
