/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 //refer to cracking the coding interview p.225
 //key is to write diagrams of 
 
 //i) initial condition w fast & slow ptr at begining
 //ii) condition after "k" steps which is when slow enters loop and fast is k steps into the loop
 // this means fast and slow are Loopsize-k steps apart
 //iii) final condition when fast and slow meet. Note that fast/slow are k steps away from loop entry
 
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (head==nullptr)
            return nullptr;
        
        ListNode* fast=head;
        ListNode* slow=head;
        
        while (fast!=nullptr){
            fast=fast->next;
            if (fast==nullptr)
                break;
            fast=fast->next;
            slow=slow->next;
            if(fast==slow)
                break;
        }
        if(fast==nullptr)
            return nullptr;
        ListNode* ptr=head;
        while(ptr!=slow){
            ptr=ptr->next;
            slow=slow->next;
        }
        return ptr;
    }
};
