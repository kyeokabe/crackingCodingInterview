
class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int R, int C, int r0, int c0) {
        vector<vector<int>> ans;
        map<vector<int>,int> m;
        int count=0;
        int step=1;
        while(ans.size()<R*C){
            if(r0>=0&&r0<R&&c0>=0&&c0<C){
                vector<int> temp={r0,c0};
                if(m.find(temp)==m.end())
                    ans.push_back(temp);
                m[temp]++;
            }
            if(count==0){
                for(int i=c0+1;i<c0+step+1;i++){
                    if(r0>=0&&r0<R&&i>=0&&i<C){
                        vector<int> temp={r0,i};
                        if(m.find(temp)==m.end())
                            ans.push_back(temp);
                        m[temp]++;
                    }
                }
                c0+=step;
            }
            else if(count==1){
                for(int i=r0+1;i<r0+step+1;i++){
                    if(i>=0&&i<R&&c0>=0&&c0<C){
                        vector<int> temp={i,c0};
                        if(m.find(temp)==m.end())
                            ans.push_back(temp);
                        m[temp]++;
                    }
                }
                r0+=step;
            }
            else if(count==2){
                for(int i=c0-1;i>c0-step-1;i--){
                    if(r0>=0&&r0<R&&i>=0&&i<C){
                        vector<int> temp={r0,i};
                        if(m.find(temp)==m.end())
                            ans.push_back(temp);
                        m[temp]++;
                    }
                }
                c0-=step;
            }
            else if(count==3){
                for(int i=r0-1;i>r0-step-1;i--){
                    if(i>=0&&i<R&&c0>=0&&c0<C){
                        vector<int> temp={i,c0};
                        if(m.find(temp)==m.end())
                            ans.push_back(temp);
                        m[temp]++;
                    }
                }  
                r0-=step;
            }
            count=((count+=1)%4);
            if(count%2==0)
                step++;
        }
        return ans;
    }
};
