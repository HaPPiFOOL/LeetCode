/*
 * @lc app=leetcode.cn id=20 lang=c
 *
 * [20] 有效的括号
 */

// @lc code=start
bool isValid(char *s)
{
    char *stack = (char *)malloc(strlen(s) * sizeof(char)); // 动态分配栈空间，大小为输入字符串长度
    int top = -1;                                           // 栈顶指针，初始值为-1表示栈空
    for (int i = 0; s[i] != '\0'; i++)
    {
        char c = s[i];
        if (c == '(' || c == '{' || c == '[')
        {
            // 将左括号压入栈中
            stack[++top] = c;
        }
        else
        {
            // 如果是右括号，检查栈顶是否匹配
            if (top == -1)
                return false;            // 栈空但遇到右括号，不匹配
            char topChar = stack[top--]; // 弹出栈顶元素
            if ((c == ')' && topChar != '(') ||
                (c == '}' && topChar != '{') ||
                (c == ']' && topChar != '['))
            {
                return false; // 不匹配
            }
        }
    }
    // 如果栈为空，说明所有括号都匹配
    return top == -1;
}
// @lc code=end
