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

    if(head->next == NULL)
        return NULL;  

    ListNode* temp = head;
    ListNode* ptr = head;
    int sz = 1;

    while(temp ->next != NULL){
        temp = temp->next;
        sz++;
    }
    if(sz == n){
        temp = head->next;
        delete head;
        return temp;
    }
    int i = 1;
    while(i < sz-n){
        ptr = ptr->next;
        i++;
    }
    
    temp = ptr->next;
    ptr->next = temp->next;
    delete temp;

    return head;
    }
};