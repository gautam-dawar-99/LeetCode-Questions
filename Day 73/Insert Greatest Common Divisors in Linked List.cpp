// problem link : https://leetcode.com/problems/insert-greatest-common-divisors-in-linked-list/
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
private:
    int GCD(int a, int b) {
        while (b != 0) {
            int tmp = b;
            b = a % b;
            a = tmp;
        }
        return a;
    }
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if (head == nullptr || head->next == nullptr){
             return head;
        }
            
        ListNode* node1 = head;
        ListNode* node2 = head->next;

        while (node2 != nullptr) {
            int gcdValue = GCD(node1->val, node2->val);
            ListNode* newNode = new ListNode(gcdValue);

            // Insert newNode between node1 and node2
            node1->next = newNode;
            newNode->next = node2;

            // Move to the next pair of nodes
            node1 = node2;
            node2 = node2->next;
        }

        return head;
    }

};