# 前 n 个数字二进制中 1 的个数

## Question
给定一个非负整数 n ，请计算 0 到 n 之间的每个数字的二进制表示中 1 的个数，并输出一个数组。

示例 1:
```
输入: n = 2
输出: [0,1,1]
解释: 
0 --> 0
1 --> 1
2 --> 10
```
示例 2:
```
输入: n = 5
输出: [0,1,1,2,1,2]
解释:
0 --> 0
1 --> 1
2 --> 10
3 --> 11
4 --> 100
5 --> 101
```

说明 :
```
0 <= n <= 105
```
来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/w3tCBm
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

## Thought

对于n来说，n/2相当于右移一个bit，0补最高位。所以n的bit个数相当于是n/2 bit个数，或者n/2 bit个数加1，当n为奇数的时候。

## Solution

```C++
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> bits(n + 1);
        for (int i = 1; i <= n; i++) {
            bits[i] = bits[i >> 1] + (i & 1);
        }
        return bits;
    }
};
```
