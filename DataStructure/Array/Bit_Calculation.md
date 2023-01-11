# Bit Calculation in Array

## Some Interesting Bit Calculation

1 利用或操作 | 和空格将英文字符转换为小写
```
('a' | ' ') = 'a'
('A' | ' ') = 'a'
```
2 利用与操作 & 和下划线将英文字符转换为大写
```
('b' & '_') = 'B'
('B' & '_') = 'B'
```
3 利用异或操作 ^ 和空格进行英文字符大小写互换
```
('d' ^ ' ') = 'D'
('D' ^ ' ') = 'd'
```
以上操作能够产生奇特效果的原因在于 ASCII 编码。ASCII 字符其实就是数字，恰巧这些字符对应的数字通过位运算就能得到正确的结果.

4 判断两个数是否异号
```
int x = -1, y = 2;
boolean f = ((x ^ y) < 0); // true

int x = 3, y = 2;
boolean f = ((x ^ y) < 0); // false
```
这个技巧还是很实用的，利用的是补码编码的符号位。如果不用位运算来判断是否异号，需要使用 if else 分支，还挺麻烦的。读者可能想利用乘积或者商来判断两个数是否异号，但是这种处理方式可能造成溢出，从而出现错误。

5 不用临时变量交换两个数
```
int a = 1, b = 2;
a ^= b;
b ^= a;
a ^= b;
// 现在 a = 2, b = 1
```
6 加一
```
int n = 1;
n = -~n;
// 现在 n = 2
```
7 减一
```
int n = 2;
n = ~-n;
// 现在 n = 1
```

8 n & n-1
```
n = n & n-1
// 可用于消除n的二进制的最后一个1
// 用于计算hamming权重以及判断是否是2次幂
```

9 ^ (异或)
```
a^a = 0
a^0 = a
// 可用于判断列表中某个突出的元素
```

## Question 1
给你一个**非空**整数数组 nums ，除了某个元素只出现一次以外，其余每个元素均出现两次。找出那个只出现了一次的元素。

你必须设计并实现线性时间复杂度的算法来解决此问题，且该算法只使用常量额外空间。

 
```
示例 1 ：
输入：nums = [2,2,1]
输出：1

示例 2 ：
输入：nums = [4,1,2,1,2]
输出：4

示例 3 ：
输入：nums = [1]
输出：1
```

提示：

1 <= nums.length <= 3 * 104

-3 * 104 <= nums[i] <= 3 * 104

除了某个元素只出现一次以外，其余每个元素均出现两次。

## Thought 1
用异或将数组中所有元素乘起来，最后的结果就是答案。

## Solution 1
```C++
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for (auto num: nums)
            ans ^= num;
        return ans;
    }
};
```

## Question 2
一个整型数组 nums 里除两个数字之外，其他数字都出现了两次。请写程序找出这两个只出现一次的数字。要求时间复杂度是O(n)，空间复杂度是O(1)。

 
```
示例 1：
输入：nums = [4,1,4,6]
输出：[1,6] 或 [6,1]

示例 2：
输入：nums = [1,2,10,4,1,4,3,3]
输出：[2,10] 或 [10,2]
```

限制：

2 <= nums.length <= 10000

## Thought 2
将所有的数字都异或起来，得到两个只出现一次数的异或。然后根据某个不为0的bit，将数组分成两组。两组的异或就是其中两个落单的元素。因为如果是成双的数字，那么由于每个bit都相同，必将分配到同一组里面，而落单的元素必将因为那个bit不同分到不同的组里。

## Solution 2
```C++
class Solution {
public:
    vector<int> singleNumbers(vector<int>& nums) {
        int product = 0;
        for (int i = 0; i < nums.size(); i++){
            product ^= nums[i];
        }
        int i = 0;
        while (product != 0){
            if ((product >> i) & 1)
                break;
            i++;
        }
        int p1 = 0, p2 = 0;
        for (int j = 0; j < nums.size(); j++){
            if ((nums[j] >> i) & 1)
                p1 ^= nums[j];
            else
                p2 ^= nums[j];
        }
        vector<int> ans = {p1, p2};
        return ans;
    }
};
```

## Question 3
在一个数组 nums 中除一个数字只出现一次之外，其他数字都出现了三次。请找出那个只出现一次的数字。

 
```
示例 1：
输入：nums = [3,4,3,3]
输出：4

示例 2：
输入：nums = [9,1,7,9,7,9,7]
输出：1
```
 

限制：

1 <= nums.length <= 10000
1 <= nums[i] < 2^31
 
## Thought 3
对于找这种在数组里面的突出元素（和其他元素不一样），可以使用位探查。
去寻找32位int中每个bit在数组里面出现的次数。如果是那种成倍的元素，这个bit 1 出现的次数也必然成倍。如果是那种落单的元素，除以这个倍数会有余数。靠这个寻找那些落单的元素。

## Solution 3
```C++
class Solution {
public:
    int power2(int n){
        int ans = 1;
        for (int i = 0; i < n; i++){
            ans *= 2;
        }
        return ans;
    }
    int singleNumber(vector<int>& nums) {
        vector<int> bitmap(32);
        int i, ans = 0;
        for (auto num: nums){
            i = 0;
            while ((num >> i) != 0){
                if ((num >> i) & 1)
                    bitmap[i]++;
                i++;
            }
        }
        for (i = 0; i < bitmap.size(); i++){
            if (bitmap[i] % 3)
                ans += power2(i);
        }
        return ans;
    }
};
```
