class Solution {
public:
    bool isRobotBounded(string ins) {
        int count=0;
        
        int N=0;
        int S=0;
        int E=0;
        int W=0;
        
        for(int i=0;i<ins.length();i++){
            if(ins[i]=='G'){
                if(count%4==0)
                    ++N;
                if(count%4==1)
                    ++E;
                if(count%4==2)
                    ++S;
                if(count%4==3)
                    ++W;
            }
            if(ins[i]=='L')
                --count;
            if(ins[i]=='R')
                ++count;
            while(count<0)
                count+=4;
        }
                
        if(N==S&&E==W||count%4!=0)
            return true;
        return false;
    }
};
