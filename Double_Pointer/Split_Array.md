# 剑指 Offer 21. 调整数组顺序使奇数位于偶数前面

## Question
输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有奇数在数组的前半部分，所有偶数在数组的后半部分。

 

示例：

输入：nums = [1,2,3,4]
输出：[1,3,2,4] 

注：[3,1,2,4] 也是正确的答案之一。
 

提示：

0 <= nums.length <= 50000

0 <= nums[i] <= 10000

## Thought
设置一个left一个right指针，left从左往右扫描，如果发现奇数继续，如果发现偶数，让right从右往左扫描，如果发现奇数则两数交换，直到left大于等于right。

## Solution

```C++
class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        // Solution 1
        // vector<int> odd, even;
        // for (int i = 0; i < nums.size(); i++){
        //     if (nums[i] % 2)
        //         odd.push_back(nums[i]);
        //     else
        //         even.push_back(nums[i]);
        // }
        // odd.insert(odd.end(), even.begin(), even.end());
        // return odd;

        // Solution 2
        int left = 0, right = nums.size() - 1;
        int temp;
        while (left < right){
            if (nums[left] % 2){
                left++;
                continue;
            }
            else{
                while (left < right){
                    if (nums[right] % 2 == 0){
                        right--;
                        continue;
                    }
                    else{
                        temp = nums[left];
                        nums[left] = nums[right];
                        nums[right] = temp;
                        break;
                    }
                }
            }
        }
        return nums;
    }
};
```

