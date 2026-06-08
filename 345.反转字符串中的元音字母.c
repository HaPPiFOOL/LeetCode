/*
 * @lc app=leetcode.cn id=345 lang=c
 *
 * [345] 反转字符串中的元音字母
 */

// @lc code=start
bool isVowel(char c)
{
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
}

void swap(char *a, char *b)
{
    char temp = *a;
    *a = *b;
    *b = temp;
}

char *reverseVowels(char *s)
{
    int i = 0;
    int j = strlen(s) - 1;

    while (i < j)
    {
        while (i < j && !isVowel(s[i]))
            i++;

        while (i < j && !isVowel(s[j]))
            j--;

        if (i < j)
        {
            swap(&s[i], &s[j]);
            i++;
            j--;
        }
    }

    return s;
}
// @lc code=end
