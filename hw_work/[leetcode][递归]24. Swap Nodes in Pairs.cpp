/*
中等
递归即可，迭代代码多。
https://leetcode.com/problems/swap-nodes-in-pairs/
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
        if (!head || !head->next) {
            return head;
        }
        ListNode* newHead = head->next;
        head->next = swapPairs(head->next->next);
        newHead->next = head;
        return newHead;
    }
};
