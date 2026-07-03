/*
 * @lc app=leetcode.cn id=495 lang=c
 *
 * [495] 提莫攻击
 */

// @lc code=start
int findPoisonedDuration(int *timeSeries, int timeSeriesSize, int duration)
{
    int totalTime = 0;
    for (int i = 1; i < timeSeriesSize; i++)
    {
        if (timeSeries[i] - timeSeries[i - 1] > duration)
        {
            totalTime += duration;
        }
        else
        {
            totalTime += timeSeries[i] - timeSeries[i - 1];
        }
    }
    // 最后一击的中毒时间
    totalTime += duration;
    
    return totalTime;
}
// @lc code=end
