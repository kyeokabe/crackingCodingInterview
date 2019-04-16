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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head==nullptr)
            return head;
        if (head->next==nullptr)
            return head;
        map <int,int> foo;
        ListNode *temp1,*temp2;
        temp1=head->next;
        temp2=head;
        foo[temp2->val]=temp2->val;
        while(temp1!=nullptr){
            auto it=foo.find(temp1->val);
            //if element is not found
            if (it==foo.end()){
                temp1=temp1->next;
                temp2=temp2->next;
                foo[temp2->val]=temp2->val;
            }
            else{//if element is found
                if (temp2->next->next==nullptr){
                    temp1=nullptr;
                    temp2->next=nullptr;
                }
                else{
                    temp2->next=temp2->next->next;
                    temp1=temp1->next;
                }
            }   
        }
        return head;
    }
};
