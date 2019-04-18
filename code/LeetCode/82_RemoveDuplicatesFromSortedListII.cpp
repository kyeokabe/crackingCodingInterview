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
        ListNode* temp=head;
        map <int,int> map1;
        map <int,int> map2;

        while(temp!=nullptr){
            auto it=map1.find(temp->val);
            if (it!=map1.end())
                map2[temp->val]=temp->val;
            map1[temp->val]=temp->val;
            temp=temp->next;
        }
        
        temp=head;
        
        bool deleteLast=false;
        
        while(temp!=nullptr){
            auto it=map2.find(temp->val);
            //if number is duplicate
            if (it!=map2.end()){
                if (temp->next==nullptr){
                    deleteLast=true;
                    temp=temp->next;
                }
                else{
                    ListNode* temp3=temp;
                    *temp=*(temp->next);
                    //delete temp3;
                }
            }
            else
                temp=temp->next;
        }
        ListNode *temp5=head;
        if(head==nullptr)
            return head;
        if(head->next==nullptr){
            if (deleteLast)
                return nullptr;
            else
                return head;
        }
        if (deleteLast){
            while(temp5->next->next!=nullptr){
                temp5=temp5->next;
            }
            temp5->next=nullptr;
        }
        return head;
    }
};
