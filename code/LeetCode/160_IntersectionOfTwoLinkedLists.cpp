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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        vector<ListNode*> foo;
        
        while (headA!=nullptr){
            foo.push_back(headA);
            headA=headA->next;
        }
        
        while (headB!=nullptr){
            for(int i=0;i<foo.size();i++){
                if(headB==foo[i])
                    return headB;
            }
            headB=headB->next;
        }
        return nullptr;
    }
};
