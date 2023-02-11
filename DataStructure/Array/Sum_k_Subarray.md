# 剑指 Offer II 010. 和为 k 的子数组

## Question

给定一个整数数组和一个整数 k ，请找到该数组中和为 k 的连续子数组的个数。

示例 1：
```
输入:nums = [1,1,1], k = 2
输出: 2
解释: 此题 [1,1] 与 [1,1] 为两种不同的情况
```
示例 2：
```
输入:nums = [1,2,3], k = 3
输出: 2
```

提示:
```
1 <= nums.length <= 2 * 104
-1000 <= nums[i] <= 1000
-107 <= k <= 107
```
 

注意：本题与主站 560 题相同： https://leetcode-cn.com/problems/subarray-sum-equals-k/

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/QTMn0o
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

## Thought

1. 此题数组中数字不一定是正数，不能用滑动窗口
2. 对于每个以idx为i结尾的子数组来说，前面的前缀为pre[i] - k即符合题目条件。所以在遍历数组的时候，到i的时候查询前面有多少个前缀为pre[i] - k的idx即可。
3. 使用mp存储pre

## Code
``` C++
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int pre = 0;
        int ans = 0;
        // 需要存储一个pre为0的idx，从而满足当前面所有数加起来为k的情况
        mp[0] = 1;
        for (int i = 0; i < nums.size();i ++){
            pre += nums[i];
            if (mp.find(pre - k) != mp.end())
                ans += mp[pre - k];
            // 在answer后面更新，从而防止k为0的时候，这个时候pre - k = pre，即使nums[i] ！= 0也会被加到答案里面
            // 每次循环的时候更新mp[pre]，从而确保只有前面的idx前缀为pre[i] - k 被考虑了进去
            mp[pre]++;
        }
        return ans;
    }
};
```