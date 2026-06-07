/*
 * @lc app=leetcode.cn id=292 lang=c
 *
 * [292] Nim 游戏
 */

// @lc code=start
bool canWinNim(int n)
{
    if (0 == n % 4)
        return false;
    return true;
}
// @lc code=end
