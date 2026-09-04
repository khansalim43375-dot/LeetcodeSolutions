class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL || head->next == NULL)
            return head;

        int n = 1;
        ListNode* tail = head;

        while (tail->next != NULL) {
            tail = tail->next;
            n++;
        }

        k = k % n;

        if (k == 0)
            return head;

        // Make circular
        tail->next = head;

        // Find new tail
        int steps = n - k - 1;
        ListNode* newTail = head;

        while (steps--)
            newTail = newTail->next;

        ListNode* newHead = newTail->next;

        // Break circle
        newTail->next = NULL;

        return newHead;
    }
};