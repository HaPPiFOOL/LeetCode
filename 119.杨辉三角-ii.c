/*
 * @lc app=leetcode.cn id=119 lang=c
 *
 * [119] 杨辉三角 II
 */

// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *getRow(int rowIndex, int *returnSize)
{
    // 该行元素总个数
    int elems = rowIndex + 1;
    *returnSize = elems;

    int *arr = (int *)malloc(sizeof(int) * elems);

    // C(n,0) = 1
    arr[0] = 1;
    // C(n,1) = C(n,0) * (n) / 1
    // C(n,2) = C(n,1) * (n - 1) / 2
    // ...
    // C(n,k) = C(n,k - 1) * (n - k + 1) / k
    for (int i = 1; i < elems; i++)
        arr[i] = 1LL * arr[i - 1] * (elems - i) / i;

    return arr;
}
// @lc code=end
