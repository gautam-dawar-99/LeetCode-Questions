// Problem Link : https://leetcode.com/problems/merge-two-sorted-lists/
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* tmp1 = list1;
        ListNode* tmp2 = list2;
        ListNode* tmp=NULL;
        ListNode* ans=NULL;
        if(tmp1 && (!tmp2 || tmp1->val <= tmp2->val)){
            tmp=tmp1;
            tmp1=tmp1->next;
        }
        else if(tmp2 && (!tmp1 || tmp1->val > tmp2->val)) {
            tmp=tmp2;
            tmp2=tmp2->next;
        }
        ans=tmp;

        while(tmp1!=nullptr && tmp2!=nullptr){
            if(tmp1->val<=tmp2->val){
                tmp->next=tmp1; 
                tmp1=tmp1->next;
            }
            else{
                tmp->next=tmp2; 
                tmp2=tmp2->next;

            }
            tmp=tmp->next;
        }
        while(tmp1!=nullptr){
            tmp->next=tmp1;
            tmp1=tmp1->next;
            tmp = tmp->next;
        }
        while(tmp2!=nullptr){
            tmp->next=tmp2;
            tmp2=tmp2->next;
            tmp = tmp->next;
        }
        return ans; 
    }
};

