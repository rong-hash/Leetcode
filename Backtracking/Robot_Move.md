# 面试题13. 机器人的运动范围

## Question
地上有一个m行n列的方格，从坐标 [0,0] 到坐标 [m-1,n-1] 。一个机器人从坐标 [0, 0] 的格子开始移动，它每次可以向左、右、上、下移动一格（不能移动到方格外），也不能进入行坐标和列坐标的数位之和大于k的格子。例如，当k为18时，机器人能够进入方格 [35, 37] ，因为3+5+3+7=18。但它不能进入方格 [35, 38]，因为3+5+3+8=19。请问该机器人能够到达多少个格子？

 

示例 1：

输入：m = 2, n = 3, k = 1
输出：3
示例 2：

输入：m = 3, n = 1, k = 0
输出：1

提示：

1 <= n,m <= 100

0 <= k <= 20

## Thought
没到一个格子去判断周围的格子是否满足题目条件，如果满足则去探索该格子。

注意：需要用一个全局的visited二维数组记录该格子是否被访问过，而不能作为一个参数传到函数里面。

## Solution

```C++
class Solution {
public:
    vector<vector<bool>> visited;
    int movingCount(int m, int n, int k) {
        int ans = 0;
        visited = vector<vector<bool>>(m, vector<bool>(n));
        ans = backtrack(0, 0, k, ans);
        return ans;
    }
    int backtrack(int i, int j, int k, int ans){
        int m = visited.size();
        int n = visited[0].size();
        string c1, c2;
        int sum;
        visited[i][j] = true;
        ans++;
        if (i < m - 1){
            if (visited[i+1][j] == false){
                sum = 0;
                c1 = to_string(i+1);
                c2 = to_string(j);
                for (auto c: c1){
                    sum += (c - '0');
                }
                for (auto c: c2){
                    sum += (c - '0');
                }
                if (sum <= k)
                    ans = backtrack(i+1, j, k, ans);
            }
        }
        if (i > 0){
            if (visited[i-1][j] == false){
                sum = 0;
                c1 = to_string(i-1);
                c2 = to_string(j);
                for (auto c: c1){
                    sum += (c - '0');
                }
                for (auto c: c2){
                    sum += (c - '0');
                }
                if (sum <= k)
                    ans = backtrack(i-1, j, k, ans);
            }
        }
        if (j < n - 1){
            if (visited[i][j+1] == false){
                sum = 0;
                c1 = to_string(i);
                c2 = to_string(j+1);
                for (auto c: c1){
                    sum += (c - '0');
                }
                for (auto c: c2){
                    sum += (c - '0');
                }
                if (sum <= k)
                    ans = backtrack(i, j+1, k, ans);
            }
        }
        if (j > 0){
            if (visited[i][j-1]== false){
                sum = 0;
                c1 = to_string(i);
                c2 = to_string(j-1);
                for (auto c: c1){
                    sum += (c - '0');
                }
                for (auto c: c2){
                    sum += (c - '0');
                }
                if (sum <= k)
                    ans = backtrack(i, j-1, k, ans);
            }
        }
        return ans;
    }
};

```