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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1==nullptr && l2==nullptr)
            return nullptr;
        if (l1==nullptr)
            return l2;
        if (l2==nullptr)
            return l1;
        ListNode* temp = l1;
        while(temp->next!=nullptr){
            temp=temp->next;
        }
        temp->next=l2; //connect l1 & l2
        temp=l1;
        vector<int> foo;
        while (temp!=nullptr){
            foo.push_back(temp->val);
            temp=temp->next;
        }

        sort(foo.begin(),foo.end());

        temp=l1;
        int count=0;
        
        while(temp!=nullptr){
            temp->val=foo[count];
            count++;
            temp=temp->next;
        }

        return l1;
    }
};
