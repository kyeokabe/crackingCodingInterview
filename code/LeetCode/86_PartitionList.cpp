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
    ListNode* partition(ListNode* head, int x) {
        queue<int> ans;
        queue<int> temp;
        ListNode* ptr=head;
        while(ptr!=nullptr){
            if (ptr->val<x)
                ans.push(ptr->val);
            else
                temp.push(ptr->val);
            ptr=ptr->next;
        }
        
        while(!temp.empty()){
            ans.push(temp.front());
            temp.pop();
        }
        
        ptr=head;
        while(ptr!=nullptr){
            ptr->val=ans.front();
            ans.pop();
            ptr=ptr->next;
        }
        
        return head;
    }
};
