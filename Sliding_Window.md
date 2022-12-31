# Sliding Window

## Question
剑指 Offer 48. 最长不含重复字符的子字符串
请从字符串中找出一个最长的不包含重复字符的子字符串，计算该最长子字符串的长度。

 

示例 1:

输入: "abcabcbb"
输出: 3 
解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。

示例 2:

输入: "bbbbb"
输出: 1
解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。

示例 3:

输入: "pwwkew"
输出: 3
解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
     请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。
 

提示：

s.length <= 40000
注意：本题与主站 3 题相同：https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/

## Thought

经典滑动窗口题目，滑动窗口其实也可以算作一种动态规划。

滑动窗口技巧
- 技巧1：双指针，用left和right表示窗口的边界。左闭右开，这样方便处理临界情况。
- 技巧2：增加right扩展窗口，增加left减小窗口。增大窗口从而找到符合情况的解，缩小窗口从而找到最优解。
- 技巧3：窗口大小为right - left。

滑动算法框架 (Cited from Labuladong)
``` C++
/* 滑动窗口算法框架 */
void slidingWindow(string s) {
    unordered_map<char, int> window;
    
    int left = 0, right = 0;
    while (right < s.size()) {
        // c 是将移入窗口的字符
        char c = s[right];
        // 增大窗口
        right++;
        // 进行窗口内数据的一系列更新
        ...

        /*** debug 输出的位置 ***/
        // 注意在最终的解法代码中不要 print
        // 因为 IO 操作很耗时，可能导致超时
        printf("window: [%d, %d)\n", left, right);
        /********************/
        
        // 判断左侧窗口是否要收缩
        while (window needs shrink) {
            // d 是将移出窗口的字符
            char d = s[left];
            // 缩小窗口
            left++;
            // 进行窗口内数据的一系列更新
            ...
        }
    }
}
```

## Solution
``` C++
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int valid = 0, maxlen = 0;
        int left = 0, right = 0;
        unordered_map<char, int> charlist;
        
        while (right < s.size()){
            char c = s[right];
            right++;
            charlist[c]++;
            while (charlist[c] > 1){
                char c2 = s[left];
                left++;
                charlist[c2]--;
            }
            if (maxlen < right - left)
                maxlen = right - left;
        }
        return maxlen;
    }
};
```

