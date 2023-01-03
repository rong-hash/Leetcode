# 剑指 Offer 12. 矩阵中的路径

## Question
给定一个 m x n 二维字符网格 board 和一个字符串单词 word 。如果 word 存在于网格中，返回 true ；否则，返回 false 。

单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母不允许被重复使用。

 

例如，在下面的 3×4 的矩阵中包含单词 "ABCCED"（单词中的字母已标出）。

![image](../img/word2.jpg "")

 

示例 1：

输入：board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
输出：true
示例 2：

输入：board = [["a","b"],["c","d"]], word = "abcd"
输出：false

## Thought
每到一个格子，判断是否和word的第一个字母吻合，如果吻合，且该词只有一个字母，返回true，如果还有其他字母，则寻找周围还没有被访问的字母。

## Solution

```C++
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<bool>> used(n, vector<bool>(m));
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                if (board[i][j] == word[0]){
                    used[i][j] = true;
                    if (backtrack(board, used, word, i, j))
                        return true;
                    used[i][j] = false;
                }
            }
        }
        return false;
    }
    bool backtrack(vector<vector<char>>& board, vector<vector<bool>>& used, string word, int i, int j){
        if (board[i][j] == word[0]){
            if (word.size() == 1)
                return true;
            else{
                if (i >= 1){
                    if (used[i - 1][j] == false){
                        used[i-1][j] = true;
                        if (backtrack(board, used, word.substr(1), i-1, j))
                            return true;
                        used[i-1][j] = false;
                    }
                }
                if (i < board.size()-1){
                    if (used[i + 1][j] == false){
                        used[i+1][j] = true;
                        if (backtrack(board, used, word.substr(1), i+1, j))
                            return true;
                        used[i+1][j] = false;
                    }
                }
                if (j >= 1){
                    if (used[i][j - 1] == false){
                        used[i][j-1] = true;
                        if (backtrack(board, used, word.substr(1), i, j - 1))
                            return true;
                        used[i][j-1] = false;
                    }
                }
                if (j < board[0].size()-1){
                    if (used[i][j + 1] == false){
                        used[i][j+1] = true;
                        if (backtrack(board, used, word.substr(1), i, j + 1))
                            return true;
                        used[i][j+1] = false;
                    }
                }
            }
        }
        return false;
    }
};
```