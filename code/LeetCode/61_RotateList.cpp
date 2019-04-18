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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head==nullptr)
            return head;
        ListNode* temp;
        temp=head;
        int count=1;
        while (temp->next!=nullptr){
            temp=temp->next;
            count++;
        }
        temp->next=head;
        temp=temp->next;
        
        k=k%count;
        if (k==count)
            return head;
        //previous step to avoid negative cout-k-1 situation
        for (int i=0;i<count-k-1;i++){
            temp=temp->next;
        }
        ListNode* newhead=temp->next;
        temp->next=nullptr;
        return newhead;
    }
};
