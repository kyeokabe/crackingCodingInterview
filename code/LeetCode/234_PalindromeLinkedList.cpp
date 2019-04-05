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
    bool isPalindrome(ListNode* head) {
        int count=0;
        ListNode *temp=head;
        stack<int> S;
        queue<int> Q;
        
        while (temp!=nullptr){
            S.push(temp->val);
            Q.push(temp->val);
            temp=temp->next;
            count++;
        }
        
        while(!S.empty()){
            if (S.top()!=Q.front())
                return false;
            S.pop();
            Q.pop();
        }
        return true;
    }
};
