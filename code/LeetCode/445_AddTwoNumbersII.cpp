class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> s1;
        stack<int> s2;
        
        ListNode* temp1=l1;
        ListNode* temp2=l2;
        
        while(temp1!=nullptr){
            s1.push(temp1->val);            
            temp1=temp1->next;
        }
        
        while(temp2!=nullptr){
            s2.push(temp2->val);
            temp2=temp2->next;
        }
        
        stack<int> s3;
        int carrier=0;
        while(!s1.empty() || !s2.empty()){
            
            int i1;
            int i2;
            
            if (s1.empty())
                i1=0;
            else
            {
                i1=s1.top();
                s1.pop();
            }
            
            if (s2.empty())
                i2=0;
            else
            {
                i2=s2.top();
                s2.pop();
            }
            //cout<<"i1 = "<<i1<<", i2 = "<<i2<<endl;
            s3.push((i1+i2+carrier)%10);
            if((i1+i2+carrier)>=10)
                carrier=1;
            else
                carrier=0;
        }
        
        if (carrier==1)
            s3.push(1);
        
        ListNode* temp = new ListNode(s3.top());
        ListNode* head=temp;
        s3.pop();
        while(!s3.empty()){
            ListNode* temp2 = new ListNode(s3.top());
            temp->next=temp2;
            temp=temp->next;
            s3.pop();
        }
        return head;
    }
};
