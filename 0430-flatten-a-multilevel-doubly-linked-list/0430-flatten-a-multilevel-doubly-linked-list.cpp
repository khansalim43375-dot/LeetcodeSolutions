/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
  Node* flatten(Node* head) {
    if (head == NULL)
        return head;

    Node* curr = head;

    while (curr != NULL) {
        if (curr->child != NULL) {
            Node* next = curr->next;

            Node* child = flatten(curr->child);

            curr->next = child;
            child->prev = curr;
            curr->child = NULL;

            while (curr->next != NULL)
                curr = curr->next;

            curr->next = next;

            if (next != NULL)
                next->prev = curr;
        }

        curr = curr->next;
    }

    return head;
}
};