// problem link : https://leetcode.com/problems/delete-nodes-from-linked-list-present-in-array/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* modifiedList(vector<int>& arr, ListNode* head) {
        unordered_set<int> ans(arr.begin(),arr.end());

        ListNode*  newNode=new ListNode(0);
        newNode->next=head;
        ListNode* prev=newNode;
        ListNode* curr=head;

        while(curr!=nullptr){
            if(ans.find(curr->val)!=ans.end()){
                prev->next=curr->next;
                delete curr;
                curr=prev->next;
            }
            else{
                prev=curr;
                curr=curr->next;
            }
        }

        return newNode->next;
        
    }
};