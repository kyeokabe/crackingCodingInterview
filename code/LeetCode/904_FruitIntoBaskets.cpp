class Solution {
public:
    int totalFruit(vector<int>& m) {
        if(m.size()<=2)
            return m.size();
        int l=0;
        int r=0;
        while(r<m.size()&&m[r]==m[l])
            r++;
        if(r==m.size())
            return m.size();
        int temp=m[r];
        while(r+1<m.size()&&((m[r+1]==temp)||(m[r+1]==m[l])))
            r++;
        if(r==m.size())
            return m.size();
        
        int ans=r-l+1;
        queue<int> q1;
        queue<int> q2;
        int int1=m[l];
        int int2=m[r];
        
        for(int i=0;i<=r;i++){
            if (m[i]==int1)
                q1.push(i);
            else q2.push(i);
        }
        
        while(r+1<=m.size()-1){

            while(!(q1.empty()||q2.empty())){
                if(q1.front()<q2.front())
                    q1.pop();
                else
                    q2.pop();
            }
            if(q1.empty()){
                q1.push(++r);
                int1=m[r];
            }
            else
            {
                q2.push(++r);
                int2=m[r];
            }
            while(r+1<=m.size()-1&&(m[r+1]==int1||m[r+1]==int2)){
                if(m[r+1]==int1)
                    q1.push(++r);
                else
                    q2.push(++r);
            }
            if(ans<q1.size()+q2.size())
                ans=q1.size()+q2.size();
        }
        return ans;
    }
};
