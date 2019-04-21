class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s3.length()!=s1.length()+s2.length())
            return false;
        if(s1==s3||s2==s3){
            return true;
        }
        int idx1=0;
        int idx2=0;
        int idx3=0;
        map<vector<int>,bool> m;

        bool ans = helper(s1,s2,s3,idx1,idx2,idx3,m);
        return ans;            
        }
           
    bool helper(string s1,string s2, string s3, int idx1, int idx2, int idx3, map<vector<int>,bool> &m){
        bool case1=false;
        bool case2=false;
        vector<int> temp = makeVec(idx1,idx2,idx3);

        auto it=m.find(temp);
        if(it!=m.end())
            return it->second;

        if (idx3==s3.length()){
            m[temp]=true;
            return true;
        }
        if (idx1<=s1.length()-1 && idx3<=s3.length()-1)
            if(s1[idx1]==s3[idx3]){
                case1=helper(s1, s2, s3, idx1+1, idx2, idx3+1,m);
                m[makeVec(idx1+1,idx2,idx3+1)]=case1;
            }        
        if (idx2<=s2.length()-1 && idx3<=s3.length()-1)        
            if (s2[idx2]==s3[idx3]){
                case2=helper(s1, s2, s3, idx1, idx2+1, idx3+1,m);
                m[makeVec(idx1,idx2+1,idx3+1)]=case2;
            }
        m[temp]=case1||case2;
        return (case1||case2);
    }
    
    vector<int> makeVec(int idx1,int idx2, int idx3){
        vector<int> temp;
        temp.push_back(idx1);
        temp.push_back(idx2);
        temp.push_back(idx3);
        return temp;
    }
    
};
