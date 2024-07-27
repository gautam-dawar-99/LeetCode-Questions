// problem link : https://leetcode.com/problems/intersection-of-two-linked-lists/
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
        ListNode *dummy1=headA;
        ListNode *dummy2=headB;

        while(dummy1!=dummy2){

            if(!dummy1) dummy1 = headA;
            else dummy1 = dummy1->next;

            if(!dummy2) dummy2 = headB;
            else dummy2 = dummy2->next;

        }
        return dummy1;
        
    }
};