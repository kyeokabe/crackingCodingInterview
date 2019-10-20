class Solution {
public:
    int balancedString(string s) {
        int Q=0,W=0,E=0,R=0; 
        
        for(int i=0;i<s.length();i++){
            if(s[i]=='Q')
                Q++;
            else if(s[i]=='W')
                W++;
            else if(s[i]=='E')
                E++;
            else if(s[i]=='R')
                R++;
        }
        
        if(Q==W&&E==R&&R==Q)
            return 0;
        
        int ans=INT_MAX;
        
        int pointR=0, pointL=0;
        int freeChar=0;
        int size=s.length();
        
        while(pointR!=size&&pointR>=pointL){
            if(NumOfUnbalanced(Q,W,E,R,size)>freeChar){
                if(s[pointR]=='Q')
                    Q--;
                if(s[pointR]=='W')
                    W--;
                if(s[pointR]=='E')
                    E--;
                if(s[pointR]=='R')
                    R--;
                freeChar++;
                pointR++;
            }
            else{
                if(pointR-pointL<ans)
                    ans=pointR-pointL;
                if(s[pointL]=='Q')
                    Q++;
                if(s[pointL]=='W')
                    W++;
                if(s[pointL]=='E')
                    E++;
                if(s[pointL]=='R')
                    R++;    
                freeChar--;
                pointL++;
            }
            //cout<<"pR= "<<pointR<<", pL= "<<pointL<<", Q = "<<Q<<", R = "<<R<<", E = "<<E<<", W = "<<W<<", free = "<<freeChar<<endl;
        }
        
        while(NumOfUnbalanced(Q,W,E,R,size)<=freeChar){
                if(pointR-pointL<ans)
                    ans=pointR-pointL;
                if(s[pointL]=='Q')
                    Q++;
                if(s[pointL]=='W')
                    W++;
                if(s[pointL]=='E')
                    E++;
                if(s[pointL]=='R')
                    R++;    
                freeChar--;
                pointL++;
        }
        
        return ans;
    }
    
    int NumOfUnbalanced(int &Q,int &W,int &E,int &R,int size){
        size=size/4;
        int deltaQ=abs(Q-size);
        int deltaW=abs(W-size);
        int deltaE=abs(E-size);
        int deltaR=abs(R-size); 
        return (deltaQ+deltaW+deltaE+deltaR);
    }
};
