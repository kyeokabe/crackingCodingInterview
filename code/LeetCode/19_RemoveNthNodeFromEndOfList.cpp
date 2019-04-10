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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head==nullptr)
            return nullptr;
        if (head->next==nullptr)
            return nullptr;        
        ListNode* temp=head;
        vector<ListNode*> foo;
        while(temp!=nullptr){
            foo.push_back(temp);
            temp=temp->next;
        }
        
        if (n==1){
            if(foo.size()==1)
                return nullptr;
            else
            {
                foo[foo.size()-1-n]->next=nullptr;
                return head;
            }
        }
        if (n==foo.size())
            return head->next;
        
        foo[foo.size()-1-n]->next=foo[foo.size()-1-n]->next->next;
        //in actuality, need to deal with memory leak
        return head;
    }
};
