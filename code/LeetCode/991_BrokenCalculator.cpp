class Solution {
public:
    int brokenCalc(int X, int Y) {
        int count=0;
        while(X!=Y){
            if(Y%2==0&&Y>X){
                Y/=2;
                count++;
            }
            else{
                Y++;
                count++;
            }
        }
        return count;
    }
};

/*
//probably correct BSF method, but there is a simpler answer
class Solution {
public:
    int brokenCalc(int X, int Y) {

        unordered_map<int,int> m;
        m[X]=0;
        
        queue<int> Q;
        Q.push(X);
 
        auto it=m.find(Y);
        while(it==m.end()){    
            int SIZE=Q.size();
 
            for(int i=0;i<SIZE;i++){
                if(Q.front()<=pow(10,9)){
                    auto it2=m.find(2*Q.front());
                    if(it2==m.end()){
                        Q.push(2*Q.front());
                        m[2*Q.front()]=m[Q.front()]+1;
                    }
                }
                if(Q.front()-1>=0){
                    auto it2=m.find(Q.front()-1);
                    if(it2==m.end()){
                        Q.push(Q.front()-1);
                        m[Q.front()-1]=m[Q.front()]+1;
                    }
                }
                Q.pop();
                it=m.find(Y);
                if(it!=m.end())
                    break;
            }
        }
        return m[Y];
    }
};
*/
