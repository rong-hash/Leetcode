# 最大礼物价值
## Question

剑指 Offer 47. 礼物的最大价值
在一个 m*n 的棋盘的每一格都放有一个礼物，每个礼物都有一定的价值（价值大于 0）。你可以从棋盘的左上角开始拿格子里的礼物，并每次向右或者向下移动一格、直到到达棋盘的右下角。给定一个棋盘及其上面的礼物的价值，请计算你最多能拿到多少价值的礼物？

 

示例 1:

输入: 
[
  [1,3,1],
  [1,5,1],
  [4,2,1]
]
输出: 12

解释: 路径 1→3→5→2→1 可以拿到最多价值的礼物
 
提示：

0 < grid.length <= 200
0 < grid[0].length <= 200

## Thought
状态转移：
对于矩阵中 grid[i][j] 为destination来说，它要么从grid[i-1][j]，要么从grid[i][j-1]中来。选grid[i][j-1]和grid[i-1][j]中路径较大值。

## Solution

``` C++

class Solution {
public:
    int maxValue(vector<vector<int>>& grid) {
        if (grid[0].size()==1 && grid.size() == 1)
            return grid[0][0];
        for (int i = 1; i < grid[0].size(); i++)
            grid[0][i] = grid[0][i]+grid[0][i-1];
        if (grid.size() == 1)
            return grid[0][grid[0].size()-1];
        for (int i = 1; i < grid.size(); i++){
            for (int j = 0; j < grid[0].size(); j++){
                if (j == 0)
                    grid[i][j] = grid[i][j] + grid[i-1][j];
                else
                    grid[i][j] = max(grid[i-1][j], grid[i][j-1]) + grid[i][j];
            }
        }
        return grid[grid.size()-1][grid[0].size()-1];
    }
};