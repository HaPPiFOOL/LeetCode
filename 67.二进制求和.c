/*
 * @lc app=leetcode.cn id=67 lang=c
 *
 * [67] 二进制求和
 */

// @lc code=start
void reverse(char *s)
{
    int len = strlen(s);
    char c;
    for (int i = 0; i < len / 2; i++)
    {
        c = s[i];
        s[i] = s[len - 1 - i];
        s[len - 1 - i] = c;
    }
    return;
}

char *addBinary(char *a, char *b)
{
    reverse(a);
    reverse(b);

    int lenA = strlen(a);
    int lenB = strlen(b);
    int maxLen = lenA > lenB ? lenA : lenB;
    char *result = (char *)malloc(sizeof(char) * (maxLen + 2));

    // 模拟全加器
    int i = 0;
    int x = 0, y = 0,cin = 0;
    while (i < lenA || i < lenB || cin)
    {
        x = (i < lenA) ? (a[i] - '0') : 0;
        y = (i < lenB) ? (b[i] - '0') : 0;
        
        result[i] = (x ^ y ^ cin) + '0';
        cin = (x & y) | (cin & (x ^ y));

        i++;
    }
    result[i] = '\0';
    reverse(result);
    return result;
}
// @lc code=end
