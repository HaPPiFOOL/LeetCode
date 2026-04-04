/*
 * @lc app=leetcode.cn id=13 lang=c
 *
 * [13] 罗马数字转整数
 */

// @lc code=start
int romanToInt(char *s)
{
    // 组数规则
    // 1. 当较大的数字符号在前，较小的在后时，将它们相加。
    // 2. 在大数左侧只能出现一个减数。
    // 3. I 只能放在 V 或 X 左边；
    // 4. X 只能放在 L 或 C 左边；
    // 5. C 只能放在 D 或 M 左边。
    // 6. V、L、D 这三个符号不能作为减数（即不能放在大数左边）。
    // 7. 相同的符号最多连续出现 3 次。
    // 8. 符号 V、L、D 永远不能重复出现（因为它们的两倍可以用 X、C、M 代替）。
    int sum = 0;
    for (int i = 0; s[i] != '\0'; i++)
    {
        switch (s[i])
        {
        case 'I':
            if (s[i + 1] == 'V' || s[i + 1] == 'X')
                sum -= 1;
            else
                sum += 1;
            break;
        case 'V':
            sum += 5;
            break;
        case 'X':
            if (s[i + 1] == 'L' || s[i + 1] == 'C')
                sum -= 10;
            else
                sum += 10;
            break;
        case 'L':
            sum += 50;
            break;
        case 'C':
            if (s[i + 1] == 'D' || s[i + 1] == 'M')
                sum -= 100;
            else
                sum += 100;
            break;
        case 'D':
            sum += 500;
            break;
        case 'M':
            sum += 1000;
            break;
        default:
            break;
        }
    }
    return sum;
}
// @lc code=end
