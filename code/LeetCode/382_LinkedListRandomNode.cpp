/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    
private:
    int COUNT;
    ListNode* ptr2;
    ListNode* head2;
    
public:
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head) {
        head2=head;
        ptr2=head;
        ListNode* ptr=head;
        int count=0;
        while(ptr!=nullptr){
            count++;
            ptr=ptr->next;
        }
        COUNT=count;
    }
    
    /** Returns a random node's value. */
    int getRandom() {
        ptr2=head2;
        int RND=rand()%COUNT;
        while(RND>0){
            ptr2=ptr2->next;
            RND--;
        }
        return ptr2->val;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */
