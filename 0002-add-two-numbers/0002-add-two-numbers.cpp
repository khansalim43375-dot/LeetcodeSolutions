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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode* curr1 = l1;
        ListNode* curr2 = l2;
        int sum,carry = 0;
        sum = curr1->val + curr2->val;
        carry = sum/10;
        if(sum > 9)  
            sum = sum % 10;
        ListNode* head = new ListNode(sum);
        ListNode* curr = head;
        curr1 = curr1->next;
        curr2 = curr2->next;
        while(curr1 != NULL || curr2 != NULL){
            if(curr1 == NULL){
              sum = curr2->val + carry;
              curr2 = curr2->next;
            }  
            else if(curr2 == NULL){  
                sum = curr1->val + carry;
                curr1 = curr1->next;
            }    
            else{    
                sum = curr1->val + curr2->val + carry;
                curr1 = curr1->next;
                curr2 = curr2->next;
            }
            carry = sum/10;
            if(sum > 9)
                sum = sum % 10;
            ListNode* temp = new ListNode(sum);
            curr->next = temp;
            curr = curr->next;
        
        }
        if(carry > 0){
            ListNode* temp = new ListNode(carry);
            curr->next = temp;
        }

        return head;
    }
};