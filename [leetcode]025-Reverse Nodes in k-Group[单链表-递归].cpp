/*
1. 原题
https://leetcode.com/problems/reverse-nodes-in-k-group/

2. 思路
题意：给定一个单链表，依次翻转k个结点。

难度中等。可以迭代处理，依次翻转，这里用的递归。
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == NULL || k == 1)
            return head;
        ListNode *pn(NULL), *p(head), *nh(head), *r(head->next);
        for (int i = 1; i < k; i++) //统计数量是否足够
        {
            p = p->next;
            if (p == NULL)
                return head;
        }
        pn = p->next;
        for (int i = 1; i < k; i++) // 翻转k个
        {
            p = r;
            r = r->next;
            p->next = nh;
            nh = p;
        }
        head->next = reverseKGroup(pn, k); // 递归处理后面的
        return nh;
    }
};
