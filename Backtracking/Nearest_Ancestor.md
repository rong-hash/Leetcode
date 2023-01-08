# 剑指 Offer 68 - II. 二叉树的最近公共祖先

## Question
给定一个二叉树, 找到该树中两个指定节点的最近公共祖先。

百度百科中最近公共祖先的定义为：“对于有根树 T 的两个结点 p、q，最近公共祖先表示为一个结点 x，满足 x 是 p、q 的祖先且 x 的深度尽可能大（一个节点也可以是它自己的祖先）。”

例如，给定如下二叉树:  root = [3,5,1,6,2,0,8,null,null,7,4]



 

示例 1:

输入: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1

输出: 3

解释: 节点 5 和节点 1 的最近公共祖先是节点 3。

示例 2:

输入: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4

输出: 5

解释: 节点 5 和节点 4 的最近公共祖先是节点 5。因为根据定义最近公共祖先节点可以为节点本身。
 

说明:

所有节点的值都是唯一的。

p、q 为不同节点且均存在于给定的二叉树中。

注意：本题与主站 236 题相同：https://leetcode-cn.com/problems/lowest-common-ancestor-of-a-binary-tree/

## Thought
深度优先搜索每个节点。

在每个节点，判断左右子树是否包含p和q。如果两棵树都包含，那么这个就是ancestor。如果只有一棵树包含，那么如果这个节点是其中一个，则这个也是ancestor。

## Solution
```C++
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        search(root, p , q);
        return ancestor;
    }
    bool search(TreeNode* root, TreeNode* p, TreeNode* q){
        if (root == NULL)
            return false;
        bool find1 = search(root->left, p, q);
        bool find2 = search(root->right, p, q);
        if ((find1 && find2) || ((find1 || find2) && (root->val == p->val || root->val == q->val))){
            ancestor = root;
        }
        return find1 || find2 || ((root->val == p->val) || (root->val == q->val));
    }
    TreeNode* ancestor;
};
```