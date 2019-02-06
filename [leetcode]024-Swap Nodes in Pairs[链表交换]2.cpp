/*
1. 原题
https://leetcode.com/problems/swap-nodes-in-pairs/

2. 思路
题意：给定一个单链表，每两个结点互相交换。

比较简单，遍历交换就好。另外，可以用递归。
*/

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
    ListNode* swapPairs(ListNode* head) {
        ListNode *s(NULL), *p(NULL), *q(NULL), *n(NULL);
        ListNode h(0);
        h.next = head;
        s = &h;

        while (1) //遍历交换
        {
            p = (s != NULL ? s->next : NULL);
            q = (p != NULL ? p->next : NULL);
            if (p == NULL || q == NULL)
                return h.next;
            n = q->next;
            q->next = p;
            p->next = n;
            s->next = q;
            s = p;
        }
        return h.next;
    }
};
