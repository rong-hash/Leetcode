## 统计范围内的元音字符串数

## Question

给你一个下标从 0 开始的字符串数组 words 以及一个二维整数数组 queries 。

每个查询 queries[i] = [li, ri] 会要求我们统计在 words 中下标在 li 到 ri 范围内（**包含**这两个值）并且以元音开头和结尾的字符串的数目。

返回一个整数数组，其中数组的第 i 个元素对应第 i 个查询的答案。

注意：元音字母是 'a'、'e'、'i'、'o' 和 'u' 。

 

示例 1：
```
输入：words = ["aba","bcb","ece","aa","e"], queries = [[0,2],[1,4],[1,1]]
输出：[2,3,0]
解释：以元音开头和结尾的字符串是 "aba"、"ece"、"aa" 和 "e" 。
查询 [0,2] 结果为 2（字符串 "aba" 和 "ece"）。
查询 [1,4] 结果为 3（字符串 "ece"、"aa"、"e"）。
查询 [1,1] 结果为 0 。
返回结果 [2,3,0] 。
```
示例 2：
```
输入：words = ["a","e","i"], queries = [[0,2],[0,1],[2,2]]
输出：[3,2,1]
解释：每个字符串都满足这一条件，所以返回 [3,2,1] 。
```

提示：
```
1 <= words.length <= 105
1 <= words[i].length <= 40
words[i] 仅由小写英文字母组成
sum(words[i].length) <= 3 * 105
1 <= queries.length <= 105
0 <= queries[j][0] <= queries[j][1] < words.length
```
来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/count-vowel-strings-in-ranges
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

## Thought

用一个数组存前i个元音word的和，那么第i + 1个 减去第j个的元素就是这个区间的元音word总和。

## Answer

```C++
class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        vector<int> prefixSum(words.size() + 1, 0); 
        unordered_set<char> seen{'a', 'e', 'i', 'o', 'u'};
        for (int i = 0; i < words.size(); ++i) {
            if (seen.count(words[i][0]) && seen.count(words[i][words[i].size()-1])) prefixSum[i + 1] = 1;
        }
        // 构造，求前缀和
        for (int i = 1; i < prefixSum.size(); ++i) {
            prefixSum[i] = prefixSum[i] + prefixSum[i - 1];
        }
        vector<int> ans(queries.size());
        for (int i = 0; i < queries.size(); ++i) {
            int right = queries[i][1], left = queries[i][0];
            ans[i] = prefixSum[right+1] - prefixSum[left];
        }
        return ans;
    }
};

```