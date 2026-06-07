/*
 * @lc app=leetcode.cn id=278 lang=c
 *
 * [278] 第一个错误的版本
 */

// @lc code=start
// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

int firstBadVersion(int n)
{
    int left = 1;
    int right = n;
    int mid = left + (right - left) / 2;

    // 二分查找
    while (left < right)
    {
        if (true == isBadVersion(mid))
            right = mid;
        else if (false == isBadVersion(mid))
            left = mid + 1;

        mid = left + (right - left) / 2;
    }
    return left;
}
// @lc code=end
