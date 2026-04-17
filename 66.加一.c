/*
 * @lc app=leetcode.cn id=66 lang=c
 *
 * [66] 加一
 */

// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *plusOne(int *digits, int digitsSize, int *returnSize)
{
    for (int i = digitsSize - 1; i >= 0; i--)
    {
        if (digits[i] < 9)
        {
            digits[i]++;
            *returnSize = digitsSize;
            return digits;
        }
        // 该位为9时，进位后该位变为0
        digits[i] = 0;
    }
    // 全部数位为9时，进位后变为100...0，即在原数组基础上增加一个数位，最高位为1，其余数位为0
    int *newDigits = (int *)calloc(digitsSize + 1, sizeof(int));
    newDigits[0] = 1;
    *returnSize = digitsSize + 1;
    return newDigits;
    /*
    int index = digitsSize - 1;
    while (index > 0 && digits[index] == 9)
    {
        digits[index] = 0;
        index--;
    }
    if (index != 0)
    {
        digits[index]++;
    }
    if (index == 0)
    {
        if (digits[index] != 9)
        {
            digits[index]++;
        }
        else if (digits[index] == 9)
        {
            digits[index] = 0;
            int *newDigits = (int *)malloc((digitsSize + 1) * sizeof(int));
            memcpy(newDigits + 1, digits, (digitsSize) * sizeof(int));
            newDigits[0] = 1;
            digitsSize++;
            *returnSize = digitsSize;
            return newDigits;
        }
    }
    *returnSize = digitsSize;
    return digits;
    */
}
// @lc code=end