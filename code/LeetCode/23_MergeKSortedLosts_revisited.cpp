/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

typedef pair<int,ListNode*> pi;

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        for(int i=0;i<lists.size();i++)
            if(lists[i]==nullptr){
                swap(lists[i],lists.back());
                lists.pop_back();
                i--;
            }
        
        pair<int, ListNode*> p;
        priority_queue<pi,vector<pi>,greater<pi>> pq;
        for(int i=0;i<lists.size();i++){
            pair<int,ListNode*> p={lists[i]->val,lists[i]};
            pq.push(p);
        }
        
        if(lists.size()==0)
            return nullptr;
        
        pair<int,ListNode*> prev=pq.top();
        ListNode* ans=prev.second;
        
        if(prev.second->next!=nullptr)
        {
            pair<int,ListNode*> temp={prev.second->next->val,prev.second->next};
            pq.push(temp);
        }
        pq.pop();
        while(pq.size()!=0){
            prev.second->next=pq.top().second;
            prev.first=pq.top().first;
            prev.second=pq.top().second;
            pq.pop();
            if(prev.second->next!=nullptr){
                pair<int,ListNode*> temp={prev.second->next->val,prev.second->next};
                pq.push(temp);
            }
        }
        return ans;
    }
};
