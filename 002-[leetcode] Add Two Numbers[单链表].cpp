/*
1. 原题 
https://leetcode.com/problems/add-two-numbers/

2. 思路
题意：给出两个链表，模拟两个十进制数进行相加，输出新的链表。基本逻辑题，不难。已AC
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        int tp;
        ListNode *pa = l1, *pb = l2, *q;
        while (pa != NULL && pb != NULL)
        {
            tp = (pa->val + pb->val + carry);
            pa->val = tp % 10;
            carry = tp / 10;
            q = pa;
            pa = pa->next;
            pb = pb->next;
        }
        
        if (pa == NULL)
        {    pa = pb;
            q->next = pa;
        }
        while(pa != NULL)
        {
            if (carry == 0)
                break;
            tp = pa->val + carry;
            pa->val = tp % 10;
            carry = tp / 10;
            q = pa;
            pa = pa->next;
        }
        if (carry > 0)
        {
            q->next = new ListNode(1);
        }
        
        return l1;
    }
};
