class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if (head==nullptr)
            return nullptr;
        vector<int> foo;
        ListNode* temp=head;
        while(temp!=nullptr){
            foo.push_back(temp->val);
            temp=temp->next;
        }
        TreeNode* ptr = new TreeNode(foo[foo.size()/2]);
        helper(ptr,foo);
        return ptr;
    }
    
    void helper(TreeNode* temp, vector<int> foo){
        if (foo.size()==0)
            return;
        cout<<" "<<endl;
        //cout<<" address "<<&temp<<endl;
        temp->val=foo[foo.size()/2];
        vector<int> left;
        vector<int> right;
        for(int i=0;i<foo.size()/2;i++)
            left.push_back(foo[i]);
        for(int i=foo.size()/2+1;i<foo.size();i++)
            right.push_back(foo[i]);
        if (right.size()!=0){
            TreeNode* ptr = new TreeNode(right[right.size()/2]);
            temp->right=ptr;
            helper(temp->right,right);
        }
        
        if (left.size()!=0){
            TreeNode* ptr = new TreeNode(left[left.size()/2]);
            temp->left=ptr;
            helper(temp->left,left);
        }        
    }  
};
