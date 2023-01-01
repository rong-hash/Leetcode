# 两个链表中的共同节点

## Question

剑指 Offer 52. 两个链表的第一个公共节点
输入两个链表，找出它们的第一个公共节点。

如下面的两个链表：
![image1](../img/common_node.png)
在节点 c1 开始相交。

 

### 示例 1：

![image2](../img/160_example_1.png)

输入：intersectVal = 8, listA = [4,1,8,4,5], listB = [5,0,1,8,4,5], skipA = 2, skipB = 3

输出：Reference of the node with value = 8

输入解释：相交节点的值为 8 （注意，如果两个列表相交则不能为 0）。从各自的表头开始算起，链表 A 为 [4,1,8,4,5]，链表 B 为 [5,0,1,8,4,5]。在 A 中，相交节点前有 2 个节点；在 B 中，相交节点前有 3 个节点。
 

### 示例 2：

![img](../img/160_example_2.png)

输入：intersectVal = 2, listA = [0,9,1,2,4], listB = [3,2,4], skipA = 3, skipB = 1

输出：Reference of the node with value = 2

输入解释：相交节点的值为 2 （注意，如果两个列表相交则不能为 0）。从各自的表头开始算起，链表 A 为 [0,9,1,2,4]，链表 B 为 [3,2,4]。在 A 中，相交节点前有 3 个节点；在 B 中，相交节点前有 1 个节点。
 

### 示例 3：

![image3](../img/160_example_3.png)

输入：intersectVal = 0, listA = [2,6,4], listB = [1,5], skipA = 3, skipB = 2

输出：null

输入解释：从各自的表头开始算起，链表 A 为 [2,6,4]，链表 B 为 [1,5]。由于这两个链表不相交，所以 intersectVal 必须为 0，而 skipA 和 skipB 可以是任意值。
解释：这两个链表不相交，因此返回 null。
 

注意：

如果两个链表没有交点，返回 null.
在返回结果后，两个链表仍须保持原有的结构。
可假定整个链表结构中没有循环。
程序尽量满足 O(n) 时间复杂度，且仅用 O(1) 内存。
本题与主站 160 题相同：https://leetcode-cn.com/problems/intersection-of-two-linked-lists/


## Thought

1. 遍历链表1，建立哈希表，再遍历链表2观察是否有共同节点

2. 一个指针走链表1，一个指针走链表2，当走到尾时切换到另一条链表上继续走。这样两个链表的结点一样时便必然是第一个共同节点。在循环的时候判断，如果都是null结束循环没有共同节点。

## Solution

``` C++
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // unordered_map<ListNode*, bool> nodemap;
        // ListNode* temp1 = headA;
        // while (temp1 != NULL){
        //     nodemap[temp1] = true;
        //     temp1 = temp1->next;
        // }
        // temp1 = headB;
        // while (temp1 != NULL){
        //     if (nodemap[temp1] == true)
        //         break;
        //     temp1 = temp1->next;
        // }
        // return temp1;

        // Solution 2
        if (headA == NULL || headB == NULL)
            return NULL;
        ListNode* tempA = headA;
        ListNode* tempB = headB;
        while (1) {
            if (headA == headB)
                break;
            if (headA == NULL && headB == NULL)
                return NULL;
            if (headA == NULL){
                headA = tempB;
                headB = headB->next;
                continue;
            }
            if (headB == NULL){
                headB = tempA;
                headA = headA->next;
                continue;
            }
            headA = headA->next;
            headB = headB->next;
        }
        return headA;
        // Official Solution
        // if (headA == nullptr || headB == nullptr) {
        //     return nullptr;
        // }
        // ListNode *pA = headA, *pB = headB;
        // while (pA != pB) {
        //     pA = pA == nullptr ? headB : pA->next;
        //     pB = pB == nullptr ? headA : pB->next;
        // }
        // return pA;

    }
};
```