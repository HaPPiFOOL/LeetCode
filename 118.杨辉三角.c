/*
 * @lc app=leetcode.cn id=118 lang=c
 *
 * [118] 杨辉三角
 */

// @lc code=start
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int **generate(int numRows, int *returnSize, int **returnColumnSizes)
{

    int **arr = (int **)malloc(sizeof(int *) * numRows);

    // 杨辉三角的行数
    *returnSize = numRows;
    // 杨辉三角每行元素的个数
    *returnColumnSizes = (int *)malloc(sizeof(int) * numRows);

    for (int i = 0; i < numRows; i++)
    {
        (*returnColumnSizes)[i] = i + 1;

        arr[i] = (int *)malloc(sizeof(int) * (i + 1));

        arr[i][0] = 1; // 行首
        arr[i][i] = 1; // 行尾

        for (int j = 1; j < i; j++)
        {
            arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
        }
    }
    return arr;
}
// @lc code=end
