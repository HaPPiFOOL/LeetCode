/*
 * @lc app=leetcode.cn id=169 lang=c
 *
 * [169] 多数元素
 */

// @lc code=start
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void maxHeapify(int *arr, int n, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && arr[l] > arr[largest])
    {
        largest = l;
    }

    if (r < n && arr[r] > arr[largest])
    {
        largest = r;
    }

    if (largest != i)
    {
        swap(&arr[i], &arr[largest]);
        maxHeapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        maxHeapify(arr, n, i);
    }

    for (int i = n - 1; i >= 0; i--)
    {
        maxHeapify(arr, i + 1, 0);
        swap(&arr[0], &arr[i]);
    }
}

int majorityElement(int *nums, int numsSize)
{
    // 排序过后，众数会出现在中间位置
    // 0 1 2 3      index = 4 / 2  
    // 0 1 2 3 4    index = 5 / 2
    heapSort(nums, numsSize);
    return nums[numsSize / 2];
}
// @lc code=end
