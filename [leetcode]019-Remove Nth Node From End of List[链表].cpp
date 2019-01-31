/*
1. 原题
https://leetcode.com/problems/remove-nth-node-from-end-of-list/

2. 思路
题意：删除单链表倒数第n个结点。
不难，采用双指针法，先让第一个指针指向第n个，然后两个指针一同遍历，直到第一个为空。
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *p(nullptr), *q(nullptr), *r(nullptr);
        p = q = head;
        for (int i = 0; i < n; i++)
            q = q->next;
        while (q != NULL)
        {
            r = p;
            p = p->next;
            q = q->next;
        }
        if (p == head) //删除头节点
        {
            p = p->next;
            delete head;
            return p;
        }
        else
        {
            r->next = p->next;
            delete p;
            return head;
        }
    }
};
