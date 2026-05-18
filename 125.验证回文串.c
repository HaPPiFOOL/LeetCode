/*
 * @lc app=leetcode.cn id=125 lang=c
 *
 * [125] 验证回文串
 */

// @lc code=start
bool isPalindrome(char *s)
{
    int slow = 0;
    int fast = 0;
    int length = strlen(s);

    while (fast < length)
    {
        if (isalnum(s[fast]))
        {
            s[slow] = tolower(s[fast]);
            slow++;
        }
        fast++;
    }
    
    int front = 0;
    int end = slow - 1;
    while (front < end)
    {
        if (s[front] != s[end])
            return false;
        front++;
        end--;
    }
    return true;
}
// @lc code=end
