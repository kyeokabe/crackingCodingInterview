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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size()==0)
            return nullptr;
        vector<int> foo;
        for(int i=0; i<lists.size();i++){
            ListNode *ptr=lists[i];
            while(ptr!=nullptr){
                foo.push_back(ptr->val);
                ptr=ptr->next;
            }
        }
        
        sort(foo.begin(),foo.end());
        
        //for(int i=0;i<foo.size();i++)
        //   cout<<foo[i];
        
        ListNode *head=nullptr;
        while(foo.size()!=0){
            ListNode *ptr;
            ptr = new ListNode(foo[foo.size()-1]);
            foo.pop_back();
            if (head==nullptr)
                ptr->next=nullptr;
            else
                ptr->next=head;
            head=ptr;
        }
        return head;
    }
};
