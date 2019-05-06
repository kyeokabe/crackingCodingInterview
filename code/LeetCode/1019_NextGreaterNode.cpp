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
    vector<int> nextLargerNodes(ListNode* head) {
        if(head==nullptr)
            return {};
        ListNode* ptr=head;
        vector<int> a;
        stack<int> n;
        stack<int> i;
        while(ptr!=nullptr){
            a.push_back(ptr->val);
            ptr=ptr->next;
        }
        
        int k=0;
        while(k<a.size()){
            if(n.empty()){
                n.push(a[k]);
                i.push(k);
            }
            else if(n.top()>=a[k]){
                n.push(a[k]);
                i.push(k);
            }
            else if(n.top()<a[k]){
                while(!n.empty()&&n.top()<a[k]){
                    a[i.top()]=a[k];
                    n.pop();
                    i.pop();
                }
                n.push(a[k]);
                i.push(k);
            }
            ++k;
        }
        while(!i.empty()){
            a[i.top()]=0;
            i.pop();
        }
        return a;
    }
};
