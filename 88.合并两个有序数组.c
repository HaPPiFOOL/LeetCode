/*
 * @lc app=leetcode.cn id=88 lang=c
 *
 * [88] 合并两个有序数组
 */

// @lc code=start
void merge(int *nums1, int nums1Size, int m, int *nums2, int nums2Size, int n)
{
    int sorted[m + n];
    int i = 0, j = 0, k = 0;
    
    while (i < m || j < n)
    {
        if (j == n)
        {
            sorted[k] = nums1[i];
            i++;
        }
        else if (i == m)
        {
            sorted[k] = nums2[j];
            j++;
        }
        else if (nums1[i] < nums2[j])
        {
            sorted[k] = nums1[i];
            i++;
        }
        else
        {
            sorted[k] = nums2[j];
            j++;
        }
        k++;
    }

    for (int i = 0; i < n + m; i++)
    {
        nums1[i] = sorted[i];
    }
}
// @lc code=end
