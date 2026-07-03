/*
 * @lc app=leetcode.cn id=482 lang=c
 *
 * [482] 密钥格式化
 */

// @lc code=start
char *licenseKeyFormatting(char *s, int k)
{
    int len = strlen(s);

    // 最大长度不会超过 2*len+1
    char *ret = malloc(len * 2 + 1);
    ret[len * 2] = '\0';

    int count = 0;
    int j = 2 * len - 1;
    for (int i = len - 1; i >= 0; i--)
    {
        if ('-' == s[i])
            continue;

        if (k == count)
        {
            ret[j--] = '-';
            count = 0;
        }

        char c = s[i];
        if (c >= 'a' && c <= 'z')
        {
            c = c - 'a' + 'A';
        }
        ret[j--] = c;
        count++;
    }

    return &ret[j + 1];
}
// @lc code=end
