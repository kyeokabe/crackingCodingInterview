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
    void reorderList(ListNode* head) {
        // if LL length is 0 or 1, return head
        if (head==nullptr || head->next==nullptr||head->next->next==nullptr)
            return;
        
        ListNode* temp;
        temp=head;
        stack<ListNode*> S;
        queue<ListNode*> Q;
        int count = 0;
        while (temp!=nullptr){
            S.push(temp);
            Q.push(temp);
            temp=temp->next;
            count++;
        }
        
        //1 2 3 4 Q
        //4 3 2 1 S
        ListNode* ptr;        
        ptr=Q.front();
        Q.pop();
        if (count%2==0){
            for (int i=0;i<count/2-1;i++){
                ptr->next=S.top();
                ptr->next->next=Q.front();
                ptr=ptr->next->next;
                S.pop();
                Q.pop();
            }
            ptr->next=S.top();
            ptr->next->next=nullptr;
            return;
        }
        
        if (count%2==1){
            for (int i=0;i<count/2;i++){
                ptr->next=S.top();
                ptr->next->next=Q.front();
                ptr=ptr->next->next;
                S.pop();
                Q.pop();
            }
            ptr->next=nullptr;
            return;
        }
    }
};
