# 剑指 Offer 55 - II. 平衡二叉树

## Question
输入一棵二叉树的根节点，判断该树是不是平衡二叉树。如果某二叉树中任意节点的左右子树的深度相差不超过1，那么它就是一棵平衡二叉树。

 

示例 1:

给定二叉树 [3,9,20,null,null,15,7]

        3
       / \
      9  20
        /  \
       15   7

返回 true 。

示例 2:

给定二叉树 [1,2,2,3,3,null,null,4,4]

          1
         / \
        2   2
       / \
      3   3
     / \
    4   4

返回 false 。

 

限制：

0 <= 树的结点个数 <= 10000

注意：本题与主站 110 题相同：https://leetcode-cn.com/problems/balanced-binary-tree/

# Thought

1. 自上而下递归，在每个节点都判断一遍是否平衡，但是时间复杂度过高，O(n^2)
2. 自下而上递归，一旦一个节点不平衡则包含这个子树的所有树都不平衡。

# Solution

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
    // bool isBalanced(TreeNode* root) {
    //     if (root == NULL)
    //         return true;
    //     int len1 = maxDepth(root->left);
    //     int len2 = maxDepth(root->right);
    //     if (len1 - len2 <= 1 && len1 - len2 >= -1)
    //         return (isBalanced(root->left) && isBalanced(root->right));
    //     else
    //         return false;
    // }
    // int maxDepth(TreeNode* root) {
    //     int len = backtrack(root, 0);
    //     return len;
    // }
    // int backtrack(TreeNode* root, int len){
    //     if (root == NULL)
    //         return len;
    //     len++;
    //     return max(backtrack(root->left, len), backtrack(root->right, len));
    // }

    bool isBalanced(TreeNode* root){
        return height(root) >= 0;
    }

    int height(TreeNode* root){
        if (root == NULL)
            return 0;
        int left = height(root->left);
        int right = height(root->right);
        if (left == -1 || right == -1 || abs(left - right) > 1)
            return -1;
        return max(left, right) + 1;
    }
};
```