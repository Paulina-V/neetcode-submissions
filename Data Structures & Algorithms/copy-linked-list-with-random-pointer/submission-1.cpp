/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> nodes;
        Node* curr = head;
        while(curr != nullptr) {
            nodes[curr] = new Node(curr->val);
            curr = curr->next;
        }
        Node* newHead = nodes[head];
        Node* newCurr = newHead;
        curr = head;
        while(curr != nullptr) {
            newCurr->next = nodes[curr->next];
            newCurr->random = nodes[curr->random];
            newCurr = newCurr->next;
            curr = curr->next;
        }
        return newHead;
    }
};
