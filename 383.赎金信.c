/*
 * @lc app=leetcode.cn id=383 lang=c
 *
 * [383] 赎金信
 */

// @lc code=start
bool canConstruct(char *ransomNote, char *magazine)
{
    int HASH[128] = {0};

    int len1 = strlen(magazine);
    for (int i = 0; i < len1; i++)
    {
        HASH[magazine[i]] += 1;
    }

    int len2 = strlen(ransomNote);
    for (int i = 0; i < len2; i++)
    {
        HASH[ransomNote[i]] -= 1;
        if (HASH[ransomNote[i]] < 0)
        {
            return false;
        }
    }
    
    return true;
}
// @lc code=end
