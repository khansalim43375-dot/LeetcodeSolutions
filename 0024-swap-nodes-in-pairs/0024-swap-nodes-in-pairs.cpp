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
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return head;

        ListNode* ans = head->next;
        ListNode* prev = NULL;
        ListNode* curr = head;

        while(curr != NULL && curr->next != NULL) {
            ListNode* second = curr->next;
            ListNode* next = second->next;

            curr->next = next;
            second->next = curr;

            if(prev != NULL)
                prev->next = second;

            prev = curr;
            curr = next;
        }

        return ans;
    }
};