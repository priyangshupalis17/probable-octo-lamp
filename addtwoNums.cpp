/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int sum(0), carry(0);
        
        ListNode *a = l1, *b = l2;
        
        ListNode* temp = new ListNode(-1);
        ListNode* t = temp;
        
        while(a || b) {
            sum = 0;
            
            if(a) {
                sum += a->val;
                a = a->next;
            }
            
            if(b) {
                sum += b->val;
                b = b->next;
            }
            
            sum += carry;
            temp->next = new ListNode(sum % 10);
            temp = temp->next;
            carry = sum / 10;
        }
        
        if(carry) temp->next = new ListNode(carry);
        
        return t->next;
    }
};
