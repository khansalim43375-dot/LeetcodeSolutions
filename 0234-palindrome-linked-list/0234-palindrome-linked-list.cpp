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
    bool isPalindrome(ListNode* head) {

        if(head->next == NULL)
            return true;
       int n = 1;
       ListNode* temp2 = head;

       while(temp2->next != NULL){
        temp2 = temp2->next;
        n++;
       }

       ListNode* prev = NULL;
       ListNode* curr = head;
       int i = 0;
       ListNode* Next;

       while(i < n/2){
        Next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = Next;
        i++;
       }
        if(n % 2 != 0)
            Next = Next->next;
            
        while(Next != NULL){
            if(Next->val != prev->val)
                return false;
            prev = prev->next;
            Next = Next->next;
        }
    return true;            

    }
};