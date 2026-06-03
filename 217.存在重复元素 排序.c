/*
 * @lc app=leetcode.cn id=217 lang=c
 *
 * [217] 存在重复元素
 */

// @lc code=start
/*
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int left, int right)
{
    int split = left;
    int base = arr[right];

    for (int i = left; i < right; i++)
    {
        if (arr[i] < base)
        {
            swap(&arr[i], &arr[split]);
            split++;
        }
    }
    swap(&arr[right], &arr[split]);
    return split;
}

void quickSort(int arr[], int left, int right)
{
    if (left < right)
    {
        int split = partition(arr, left, right);
        quickSort(arr, left, split - 1);
        quickSort(arr, split + 1, right);
    }
}
*/
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

bool containsDuplicate(int *nums, int numsSize)
{
    heapSort(nums, numsSize);

    for (int i = 1; i < numsSize; i++)
        if (nums[i] == nums[i - 1])
            return true;

    return false;
}
// @lc code=end
