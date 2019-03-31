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
    bool hasCycle(ListNode *head) {
        if (head==nullptr) return false;
        if (head->next==head) 
            return true;
        ListNode *temp1=head;
        ListNode *temp2=head;
        while(temp2->next!=nullptr){
            temp1=temp1->next;
            temp2=temp2->next;
            if (temp2->next!=nullptr)
                temp2=temp2->next;
            else
                return false;
            if (temp1==temp2)
                return true;

        }
        return false;
    }
};
