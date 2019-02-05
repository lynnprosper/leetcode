/*
1. 原题
https://leetcode.com/problems/merge-k-sorted-lists/

2. 思路
题意：给出k个有序链表，合并成一个。

思路：有多种方法。这里采用逐次合并两个链表，共k-1次。

时间复杂度O(k*N). 可以利用优先队列的性质可以，复杂度为O(N*logk).
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty())
            return NULL;
        ListNode head(0), *p(NULL), *q(NULL), *r(NULL), *t(NULL);
        head.next = lists[0];
        
        for (int i = 1; i < lists.size(); i++) //比较两个链表，共k-1次。
        {
            p = &head;
            q = p->next;
            r = lists[i];
            while(q && r)
            {
                if (q->val < r->val)
                {
                    p = q;
                    q = q->next;
                }
                else
                {
                    t = r->next;
                    r->next = q;
                    p->next = r;
                    p = r;
                    r = t;
                }
            }
            if (r)
            {
                p->next = r;
            }
        }
        
        return head.next;
    }
    
    
};
