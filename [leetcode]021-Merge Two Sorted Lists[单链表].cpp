/*
1. 原题
https://leetcode.com/problems/merge-two-sorted-lists/

2. 思路
题意：给出两个有序单链表，合并一个有序单链表。

比较简单，两个链表同时判断就好。
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == NULL)
            return l2;
        if (l2 == NULL)
            return l1;
        ListNode *p(NULL), *q(NULL), *r(NULL), *res(NULL);
        if (l1->val < l2->val)
        {
            r = res = l1; //r是新链表的尾指针
            p = r->next;
            q = l2;
        }
        else
        {
            r = res = l2;
            p = r->next;
            q = l1;
        }
        
        while(p && q)
        {
            if (p->val < q->val)
            {
                r->next = p;
                p = p->next;
                r = r->next;
            }
            else
            {
                r->next = q;
                q = q->next;
                r = r->next;
            }
        }
        if (p)
            r->next = p;
        else
            r->next = q;
        
        return res;
    }
};
