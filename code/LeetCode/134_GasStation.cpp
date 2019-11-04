class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalGas=0;
        int totalCost=0;
        for(int i=0;i<gas.size();i++){
            totalGas+=gas[i];
            totalCost+=cost[i];
        }
        if(totalCost>totalGas)
            return -1;
        
        int start=0;
        int finish=0;
        totalGas=0;
        totalCost=0;
        
        while((start+1)%gas.size()!=finish){
            totalGas+=gas[start];
            totalCost+=cost[start];
            while(totalCost>totalGas&&start>=finish){
                totalCost-=cost[finish];
                totalGas-=gas[finish];
                finish=(finish+1)%gas.size();
            }
            start=(start+1)%gas.size();
        }
        return finish;
    }
    
};

//TLE
/*
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        for(int i=0;i<gas.size();i++){
            int goal=i;
            if(cancirculate(gas,cost,i,goal,gas[i]))
                return i;
        }
        return -1;
    }
    
    bool cancirculate(vector<int>& gas, vector<int>& cost, int current,const int goal, int tank){
        
        int next=(current+1)%gas.size();
        if(next==goal&&tank-cost[current]>=0)
            return true;
        if(tank-cost[current]<0)
            return false;
        return cancirculate(gas,cost,next,goal,tank-cost[current]+gas[next]);
    }
    
};
*/
