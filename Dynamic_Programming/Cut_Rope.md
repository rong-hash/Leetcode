# 剑指 Offer 14- I. 剪绳子

## Question
给你一根长度为 n 的绳子，请把绳子剪成整数长度的 m 段（m、n都是整数，n>1并且m>1），每段绳子的长度记为 k[0],k[1]...k[m-1] 。请问 k[0]*k[1]*...*k[m-1] 可能的最大乘积是多少？例如，当绳子的长度是8时，我们把它剪成长度分别为2、3、3的三段，此时得到的最大乘积是18。
```
示例 1：
输入: 2
输出: 1
解释: 2 = 1 + 1, 1 × 1 = 1

示例 2:
输入: 10
输出: 36
解释: 10 = 3 + 3 + 4, 3 × 3 × 4 = 36
```
提示：

2 <= n <= 58

注意：本题与主站 343 题相同：https://leetcode-cn.com/problems/integer-break/

## Thought
用动态规划。f(n) = max(i * f(n-i), i * (n-i)) for all i between 1 to n/2。其中 f(n) 可以用一个数组存储从而减小重复运算。

## Solution
```C++
class Solution {
public:
    int cuttingRope(int n) {
        cache = vector<int>(n + 1);
        int ans = backtracking(n);
        return ans;
    }
    int backtracking(int n){
        if (n == 1)
            return 1;
        int ans = 0, temp;
        for (int i = 1; i <= n / 2; i++){
            if (cache[n-i] != 0){
                temp = cache[n-i];
            }
            else{
                temp = backtracking(n-i);
                cache[n-i] = temp;
            }
            temp = max(i * temp, i * (n-i));
            if (temp > ans)
                ans = temp;
        }
        return ans;
    }
private:
    vector<int> cache;
};
```

