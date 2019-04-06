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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *ptr1=l1;
        ListNode *ptr2=l2;
        int count = 0;
        int nums1 = 0;
        int nums2 = 0;
        queue<int> Q1;
        queue<int> Q2;
        queue<int> Q3;
        
        while(ptr1!=nullptr){
            count++;
            Q1.push(ptr1->val);
            ptr1 = ptr1->next;
        }
        
        nums1 = count;
        count = 0;
        
        while(ptr2!=nullptr){
            count++;
            Q2.push(ptr2->val);
            ptr2=ptr2->next;
        }  
        
        nums2 = count;
        
        int carry = 0;
        
        while((!Q1.empty()) || (!Q2.empty())||carry!=0)
        {
            int a=0;
            int b=0;
            if (!Q1.empty()){
                a=Q1.front();
                Q1.pop();
            }
            if (!Q2.empty()){
                b=Q2.front();
                Q2.pop();
            }
            
            if (a+b+carry>=10){
                Q3.push((a+b+carry)%10);
                carry=1;
            }
            else{
                Q3.push(a+b+carry);
                carry=0;
                }
        }
        
        stack<int> Q4;
        while(!Q3.empty()){
            Q4.push(Q3.front());
            Q3.pop();
        }
        
        ListNode *tmp;
        tmp=nullptr;
        while(!Q4.empty()){
            ListNode *foo=new ListNode(Q4.top());
            foo->next=tmp;
            tmp=foo;
            Q4.pop();
        }
        return tmp;
    }
};
