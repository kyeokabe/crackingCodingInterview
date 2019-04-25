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
    int numComponents(ListNode* head, vector<int>& G) {
        if (head==nullptr)
            return 0;
        map<int,int> foo;
        for(int i=0;i<G.size();i++){
            foo[G[i]]=G[i];
        }
        int ans=0;
        int listlength=0;
        ListNode* temp=head;
        
        while(temp!=nullptr){
            listlength++;
            temp=temp->next;
        }
        
        bool iselement=false;
        temp=head;
        for(int i=0;i<listlength;i++){
            auto it=foo.find(temp->val);
            if (iselement==false&&it!=foo.end()){
                ans++;
                iselement=true;
            }
            else if(iselement==false&&it==foo.end())
                iselement=false;
            else if(iselement==true&&it!=foo.end())
                iselement=true;
            else if(iselement==true&&it==foo.end())
                iselement=false;
            temp=temp->next;
        }
        return ans;
    }
};
