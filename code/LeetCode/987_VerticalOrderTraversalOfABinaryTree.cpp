/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {

        int cheight,cleft,cright,mheight,mleft,mright;
        cheight,cleft,cright,mheight,mleft,mright=0;
        
        getdims(cheight,cleft,cright,mheight,mleft,mright,root);
        //vector<vector<vector<int>>> v(mheight+1,vector<int>(mright+mleft+1,vector<int>(1,INT_MIN)));
        vector<vector<vector<int>>> v;
        vector<vector<int>> v2(mright+mleft+1,vector<int>(1,INT_MIN));
        for(int i=0;i<mheight+1;i++)
            v.push_back(v2);

        help (root,v,0,0,mleft);
        vector<vector<int>> ans;
                
        for(int j=0;j<v[0].size();j++){
            vector<int> foo;
            for(int i=0;i<v.size();i++)
                if(v[i][j][0]!=INT_MIN)
                    for(int k=0;k<v[i][j].size();k++)
                        foo.push_back(v[i][j][k]);
            if(foo.size()!=0)
                ans.push_back(foo);
        }
        
        return ans;
    }
    
    void getdims(int cheight,int cleft,int cright,int &mheight,int &mleft,int &mright, TreeNode* root){
        if(root==nullptr)
            return;
        if(cheight>mheight)
            mheight=cheight;
        if(cleft>mleft)
            mleft=cleft;
        if(cright>mright)
            mright=cright;
        getdims(cheight+1,cleft+1,cright,mheight,mleft,mright,root->left);
        getdims(cheight+1,cleft,cright+1,mheight,mleft,mright,root->right);
    }
    
    void help(TreeNode* root, vector<vector<vector<int>>> &v, int height,int rlcount,int mleft){
        if(root==nullptr)
            return;
        if(v[height][rlcount+mleft][0]==INT_MIN)
            v[height][rlcount+mleft][0]=root->val;
        else{
            vector<int> foo=v[height][rlcount+mleft];
            foo.push_back(root->val);
            sort(foo.begin(),foo.end());
            v[height][rlcount+mleft]=foo;
        }
        help(root->left,v,height+1,rlcount-1,mleft);
        help(root->right,v,height+1,rlcount+1,mleft);
    }
};
