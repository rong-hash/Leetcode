# 寻找重复数字

## Question
找出数组中重复的数字。


在一个长度为 n 的数组 nums 里的所有数字都在 0～n-1 的范围内。数组中某些数字是重复的，但不知道有几个数字重复了，也不知道每个数字重复了几次。请找出数组中任意一个重复的数字。

示例 1：

输入：
[2, 3, 1, 0, 2, 5, 3]   输出：2 或 3 
 

限制：

2 <= n <= 100000

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/shu-zu-zhong-zhong-fu-de-shu-zi-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

## Thought

法一：用哈希表，简洁暴力但是空间复杂度O(n)

法二：用交换。每次遇到一个和自身index不相同的数字时，和index所存放的数字进行交换。如果index所存放的数字和index相同，则表示有重复数字，返回index。

此方法要点：不能使用for loop。因为当交换完毕后，需要继续判断交换后的数字是否和当前index相同，如果不同则需要继续交换。


## Solution
``` C++
#include <map>

class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        // method 1:
        // map<int, int> table;
        // int i;
        // for (i = 0; i < nums.size(); i++){
        //     if (table.find(nums[i]) == table.end())
        //         table.insert({nums[i], 1});
        //     else
        //         break;
        // }
        // return nums[i];


        // method 2
        int i = 0;
        while (i < nums.size()){
            if (i == nums[i]){
                i++;
                continue;
            }
            if (nums[nums[i]] == nums[i]){
                return nums[i];
            }
            swap(nums[i], nums[nums[i]]);
        }
        return -1;
    }
};
```
