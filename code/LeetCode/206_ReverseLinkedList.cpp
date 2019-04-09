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
    ListNode* reverseList(ListNode* head) {
        if (head==nullptr)
            return head;
        ListNode* temp=head;
        stack<int> foo;
        while (temp!=nullptr){
            foo.push(temp->val);
            temp=temp->next;
        }
        temp=head;
        while (temp!=nullptr){
            temp->val=foo.top();
            foo.pop();
            temp=temp->next;
        }
        return head;
    }
};
