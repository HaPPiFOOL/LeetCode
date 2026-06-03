/*
 * @lc app=leetcode.cn id=225 lang=c
 *
 * [225] 用队列实现栈
 */

// @lc code=start

typedef struct
{
    int *data;
    int head;
    int rear;
    int size;
    int elems;
} Queue;

Queue *initQueue(int k)
{
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    queue->data = (int *)malloc(sizeof(int) * k);
    queue->head = 0; // 指向队首元素
    queue->rear = 0; // 指向队尾元素的后一个元素
    queue->size = k;
    queue->elems = 0;
    return queue;
}

void in(Queue *obj, int x)
{
    obj->data[obj->rear] = x;
    obj->rear = (obj->rear + 1) % obj->size;
    obj->elems++;
}

int out(Queue *obj)
{
    int x = obj->data[obj->head];
    obj->head = (obj->head + 1) % obj->size;
    obj->elems--;
    return x;
}

bool empty(Queue *obj)
{
    return 0 == obj->elems;
}

typedef struct
{
    Queue *queue;
} MyStack;

MyStack *myStackCreate()
{
    MyStack *obj = (MyStack *)malloc(sizeof(MyStack));
    obj->queue = initQueue(100);
    return obj;
}

void myStackPush(MyStack *obj, int x)
{
    in(obj->queue, x);

    for (int i = 0; i < obj->queue->elems - 1; i++)
    {
        int x = out(obj->queue);
        in(obj->queue, x);
    }
}

int myStackPop(MyStack *obj)
{
    return out(obj->queue);
}

int myStackTop(MyStack *obj)
{
    return obj->queue->data[obj->queue->head];
}

bool myStackEmpty(MyStack *obj)
{
    return empty(obj->queue);
}

void myStackFree(MyStack *obj)
{
    free(obj->queue->data);
    free(obj->queue);
    free(obj);
}

/**
 * Your MyStack struct will be instantiated and called as such:
 * MyStack* obj = myStackCreate();
 * myStackPush(obj, x);

 * int param_2 = myStackPop(obj);

 * int param_3 = myStackTop(obj);

 * bool param_4 = myStackEmpty(obj);

 * myStackFree(obj);
*/
// @lc code=end
