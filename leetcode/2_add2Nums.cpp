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
        int carry = 0;
        ListNode *head = nullptr;
        ListNode *prev = nullptr;
        while ((l1 != nullptr) && (l2 != nullptr)) {
            int sum = l1->val + l2->val + carry;
            carry = sum/10;
            sum = sum%10;
            
            ListNode *newNode = new ListNode(sum);
            
            if (!head){
                head = newNode;
                prev = newNode;
            } else {
                prev->next = newNode;
                prev = prev->next;
            }
            
            l1 = l1->next;
            l2 = l2->next;
        }
        
        while (l1 != nullptr) {
            int sum = l1->val + carry;
            carry = sum/10;
            sum = sum%10;
            
            ListNode *newNode = new ListNode(sum);
            
            if (!head){
                head = newNode;
                prev = newNode;
            } else {
                prev->next = newNode;
                prev = prev->next;
            }
            l1 = l1->next;
        }
        
        while (l2 != nullptr) {
            int sum = l2->val + carry;
            carry = sum/10;
            sum = sum%10;
            
            ListNode *newNode = new ListNode(sum);
            
            if (!head){
                head = newNode;
                prev = newNode;
            } else {
                prev->next = newNode;
                prev = prev->next;
            }
            l2 = l2->next;
        }
        
        if (carry) {
            ListNode *newNode = new ListNode(carry);
            prev->next = newNode;
        }
        
        return head;
    }
};