/*
 * @lc app=leetcode.cn id=463 lang=c
 *
 * [463] 岛屿的周长
 */

// @lc code=start
int dfs(int x, int y, int **grid, int n, int m)
{
    // 方向偏移向量
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};

    // 遇到边界或遇到水域时边长 +1
    if (x < 0 || x >= n || y < 0 || y >= m || grid[x][y] == 0)
    {
        return 1;
    }
    
    // 如果访问过该岛屿则直接跳过
    if (grid[x][y] == 2)
    {
        return 0;
    }

    // 访问标记，永远不会标记水域
    if (1 == grid[x][y])
        grid[x][y] = 2;

    // 利用方向偏移向量遍历该岛屿四周的区域
    int res = 0;
    for (int i = 0; i < 4; ++i)
    {
        int tx = x + dx[i];
        int ty = y + dy[i];
        res += dfs(tx, ty, grid, n, m);
    }
    return res;
}

int islandPerimeter(int **grid, int gridSize, int *gridColSize)
{
    int row = gridSize;
    int col = *gridColSize;
    int cir = 0;
    // 图的深度优先遍历
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            // 访问没有访问过的岛屿
            if (1 == grid[i][j])
            {
                cir += dfs(i, j, grid, row, col);
            }
        }
    }
    return cir;
}
// @lc code=end
