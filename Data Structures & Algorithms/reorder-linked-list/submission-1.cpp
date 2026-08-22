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
    void reorderList(ListNode* head) {
        ListNode* slowPointer = head;
        ListNode* fastPointer = head;
        while(fastPointer->next &&fastPointer->next->next) {
            slowPointer = slowPointer->next;
            fastPointer = fastPointer->next->next;
        }
        // slow is on the middle node or the middle below half now 
        // now we gotta reverse the items that starting from slow->next
        
        ListNode* secondHalfHead = slowPointer->next;
        ListNode* curr = secondHalfHead;
        ListNode* prev = nullptr;
        while(curr) {
            ListNode* t;
            t = curr->next;
            curr->next = prev;
            prev = curr;
            curr = t;
        }
        secondHalfHead = prev;
        slowPointer->next = nullptr;


        curr = head;
        while(secondHalfHead) {
            ListNode* temp = curr->next;
            ListNode* temp2 = secondHalfHead->next;

            curr->next = secondHalfHead;
            curr->next->next = temp; 
            secondHalfHead = temp2;
            curr = temp;
        }
    }
};
