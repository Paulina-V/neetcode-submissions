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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int total = 0;
        ListNode* copy = head;
        while(copy) {
            total++;
            copy = copy->next;
        }
        if(!head->next) return nullptr;

        /*
        0   1   2   
                c
        ct = 0
        goal = 0
        */
        int count = 0;
        ListNode dummy(0);
        dummy.next = head;
        ListNode* curr = &dummy;

        while(curr->next) {
            cout << " count: " << count;
            cout << " currval: " << curr->val << "\n";
            if(count == total - n) {
                //if()
                cout << count;
                curr->next = curr->next->next;
            }
            if(curr->next) {curr = curr->next;}
            count++;
        }
        
        return dummy.next;
    }
};
