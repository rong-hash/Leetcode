# 连续子数组的最大和

## Question
剑指 Offer 42. 连续子数组的最大和
输入一个整型数组，数组中的一个或连续多个整数组成一个子数组。求所有子数组的和的最大值。

要求时间复杂度为O(n)。

 

示例1:

输入: nums = [-2,1,-3,4,-1,2,1,-5,4]
输出: 6

解释: 连续子数组 [4,-1,2,1] 的和最大，为 6。
 

提示：

1 <= arr.length <= 10^5
-100 <= arr[i] <= 100
注意：本题与主站 53 题相同：https://leetcode-cn.com/problems/maximum-subarray/

## Thought
状态转移：用一个dp array存储数组中每个数结尾的最大和。
如果dp[n-1]为负，则最大值就是nums[i]。如果dp[n-1]为正，最大值则是dp[n-1]+nums[i]

## Solution

``` C++
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans;
        for (int i = 1; i < nums.size(); i++){
            if (nums[i-1] < 0){
                nums[i] = nums[i];
            }
            else    
                nums[i] = nums[i] + nums[i-1];
        }
        ans = nums[0];
        for (int i = 0; i < nums.size(); i++){
            if (nums[i] > ans)
                ans = nums[i];
        }
        return ans;
    }
};
```
