# 剑指 Offer 66. 构建乘积数组

## Question
给定一个数组 A[0,1,…,n-1]，请构建一个数组 B[0,1,…,n-1]，其中 B[i] 的值是数组 A 中除了下标 i 以外的元素的积, 即 B[i]=A[0]×A[1]×…×A[i-1]×A[i+1]×…×A[n-1]。不能使用除法。

 
```
示例:

输入: [1,2,3,4,5]
输出: [120,60,40,30,24]
```

提示：

所有元素乘积之和不会溢出 32 位整数

a.length <= 100000

## Thought
设计一个左数组和右数组。左数组每个元素代表着从左往右到该元素index的乘积，右数组同理。其中右数组可以优化成一个常数，左数组可以存放最后的ans，所以时间复杂度O(n)，右数组O(1)。

## Solution
```C++
class Solution {
public:
    vector<int> constructArr(vector<int>& a) {
        vector<int> ans(a.size());
        if (a.size() == 0)
            return ans;
        ans[0] = 1;
        for (int i = 1; i < a.size(); i++){
            ans[i] = ans[i-1] * a[i-1];
        }
        int R = 1;
        for (int i = a.size() - 1; i >= 0; i--){
            ans[i] = ans[i] * R;
            R = R * a[i];
        }
        return ans;
    }
};
```