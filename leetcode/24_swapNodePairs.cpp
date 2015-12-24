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
    ListNode* swapPairs(ListNode* head) {
        if (!head) return head;
        if(!head->next) return head;
        
        ListNode *ptr1,*ptr2,*prev = nullptr;
        ptr1 = head;
        ptr2 = head;
        head = ptr1->next;
        while(ptr2 != nullptr){
            if(ptr1->next == nullptr) break;
            ptr2 = ptr2->next->next;
            if(prev) prev->next = ptr1->next;
            prev = ptr1;
            ptr1->next->next = ptr1;
            ptr1->next = ptr2;
            ptr1 = ptr2;
        }
        
        return head;
    }
};