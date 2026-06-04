/*
 * @lc app=leetcode.cn id=232 lang=c
 *
 * [232] 用栈实现队列
 */

// @lc code=start

typedef struct
{
    int *data;
    int top;
} Stack;

Stack *initStack()
{
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    stack->data = (int *)malloc(sizeof(int) * 100);
    stack->top = 0;
    return stack;
}

void push(Stack *obj, int x)
{
    obj->data[obj->top] = x;
    obj->top++;
}

int pop(Stack *obj)
{
    obj->top--;
    return obj->data[obj->top];
}

bool empty(Stack *obj)
{
    return 0 == obj->top;
}

typedef struct
{
    Stack *stack1;
    Stack *stack2;
} MyQueue;

MyQueue *myQueueCreate()
{
    MyQueue *queue = (MyQueue *)malloc(sizeof(MyQueue));
    queue->stack1 = initStack();
    queue->stack2 = initStack();
    return queue;
}

void myQueuePush(MyQueue *obj, int x)
{
    int n;

    n = obj->stack1->top;
    for (int i = 0; i < n; i++)
    {
        int val = pop(obj->stack1);
        push(obj->stack2, val);
    }

    push(obj->stack2, x);

    n = obj->stack2->top;
    for (int i = 0; i < n; i++)
    {
        int val = pop(obj->stack2);
        push(obj->stack1, val);
    }
}

int myQueuePop(MyQueue *obj)
{
    return pop(obj->stack1);
}

int myQueuePeek(MyQueue *obj)
{
    return obj->stack1->data[obj->stack1->top - 1];
}

bool myQueueEmpty(MyQueue *obj)
{
    return empty(obj->stack1);
}

void myQueueFree(MyQueue *obj)
{
    if (obj == NULL)
        return;

    free(obj->stack1->data);
    free(obj->stack1);

    free(obj->stack2->data);
    free(obj->stack2);

    free(obj);
}

/**
 * Your MyQueue struct will be instantiated and called as such:
 * MyQueue* obj = myQueueCreate();
 * myQueuePush(obj, x);

 * int param_2 = myQueuePop(obj);

 * int param_3 = myQueuePeek(obj);

 * bool param_4 = myQueueEmpty(obj);

 * myQueueFree(obj);
*/
// @lc code=end
