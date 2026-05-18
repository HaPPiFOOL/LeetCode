/*
 * @lc app=leetcode.cn id=121 lang=c
 *
 * [121] 买卖股票的最佳时机
 */

// @lc code=start
int maxProfit(int *prices, int pricesSize)
{
    int profit = 0;
    int maxProfit = 0;
    int lowestPrice = prices[0];

    // 在今天(第i天)卖出
    for (int i = 0; i < pricesSize; i++)
    {
        profit = prices[i] - lowestPrice;
        maxProfit = profit > maxProfit ? profit : maxProfit;
        lowestPrice = prices[i] > lowestPrice ? lowestPrice : prices[i];
    }
    return maxProfit;
}
// @lc code=end
