/*
 * @lc app=leetcode.cn id=455 lang=c
 *
 * [455] 分发饼干
 */

// @lc code=start
int cmp(const void *a, const void *b)
{
    int arg1 = *(int *)a;
    int arg2 = *(int *)b;
    if (arg1 < arg2)
        return -1;
    if (arg1 > arg2)
        return 1;
    return 0;
}

int findContentChildren(int *g, int gSize, int *s, int sSize)
{
    qsort(g, gSize, sizeof(int), cmp);
    qsort(s, sSize, sizeof(int), cmp);

    int contented = 0;
    int i = 0;
    int j = 0;
    while (i < gSize && j < sSize)
    {
        if (g[i] <= s[j])
        {
            contented++;
            i++;
        }
        j++;
    }
    return contented;
}
// @lc code=end
