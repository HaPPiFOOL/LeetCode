/*
 * @lc app=leetcode.cn id=374 lang=c
 *
 * [374] 猜数字大小
 */

// @lc code=start
/**
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */
int guess(int num);
int guessNumber(int n)
{
    int left = 1;
    int right = n;

    while (true)
    {
        int mid = left + (right - left) / 2;
        if (guess(mid) == -1)
        {
            right = mid - 1;
        }

        if (guess(mid) == 1)
        {
            left = mid + 1;
        }

        if (guess(mid) == 0)
        {
            return mid;
        }
    }
}
// @lc code=end
