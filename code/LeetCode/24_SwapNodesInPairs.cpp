/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
 // forgot to pass reference of pointer first time...
 //
 
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head==nullptr)
            return head;
        if (head->next==nullptr)
            return head;
        helper (head);

        return head;
    }
    
    void helper(ListNode* &head){
        if (head!=nullptr)
            if (head->next!=nullptr){
                ListNode* temp1=head;
                ListNode* temp2=head->next;
                
                head=temp2;
                temp1->next=temp2->next;
                temp2->next=temp1;
                helper(head->next->next);
        }
    }
    
};
