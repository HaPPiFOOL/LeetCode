/*
 * @lc app=leetcode.cn id=303 lang=c
 *
 * [303] 区域和检索 - 数组不可变
 */

// @lc code=start

typedef struct
{
    // 0 : sum[0:0] = 0
    // 1 : sum[0:1] = 0 + 1
    // 2 : sum[0:2] = 0 + 1 + 2
    // ...
    // n : sum[0:n] = 0 + 1 + ... + n
    int *nums;
} NumArray;

NumArray *numArrayCreate(int *nums, int numsSize)
{
    NumArray *obj = malloc(sizeof(NumArray));
    obj->nums = malloc(sizeof(int) * numsSize);

    obj->nums[0] = nums[0];
    for (int i = 1; i < numsSize; i++)
    {
        obj->nums[i] = obj->nums[i - 1] + nums[i];
    }

    return obj;
}

int numArraySumRange(NumArray *obj, int left, int right)
{
    if (left > 0)
    {
        return obj->nums[right] - obj->nums[left - 1];
    }
    
    return obj->nums[right];
}

void numArrayFree(NumArray *obj)
{
    free(obj->nums);
    free(obj);
}

/**
 * Your NumArray struct will be instantiated and called as such:
 * NumArray* obj = numArrayCreate(nums, numsSize);
 * int param_1 = numArraySumRange(obj, left, right);

 * numArrayFree(obj);
*/
// @lc code=end
