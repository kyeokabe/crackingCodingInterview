class Solution {
public:
    double probabilityOfHeads(vector<double>& prob, int target) {
        
        if(target==0){
            int i=0;
            double P=1;
            while(i<prob.size()){
                P=P*double(1-prob[i]);
                i++;
            }
            return P;
        }
             
        vector<double> v2(target+1,0);
        vector<vector<double>> v(prob.size(),v2);
        //v[i][j] is probability that after ith coin flipped, j were heads
        
        //first, calculate probability of ith coin flipped, 0 were heads
        v[0][1]=prob[0];
        v[0][0]=1-prob[0];

        for(int i=1;i<prob.size();i++)
            v[i][0]=v[i-1][0]*(1-prob[i]);
        

        for(int i=1;i<prob.size();i++)
            for(int j=1;j<=min(i+1,target);j++){
                v[i][j]=v[i-1][j]*(1-prob[i])+v[i-1][j-1]*prob[i];
            }
        
        return v[prob.size()-1][target];
    }
};

/*
class Solution {
public:
    double probabilityOfHeads(vector<double>& prob, int target) {
        
        vector<vector<int>> v;
        vector<int> v2;
        
        //make all index combinations
        combinations(v,target,v2,prob);
        
        //calculate its probability        
        double ans=0;
        if(v[0].size()==0){
            double P=1;
            for(int i=0;i<prob.size();i++)
                P*=(1-prob[i]);
            return P;
        }
        
        for(int i=0;i<v.size();i++)
            ans+=calculateP(v[i],prob);
        return ans;
    }
    
    
    double calculateP(vector<int> &v,vector<double>& prob){
        int i=0;
        int j=0;
        double P=1.0;
        while(i<prob.size()){
            if(j<v.size()&&i==v[j]){
                P*=prob[i];
                j++;
            }
            else
                P*=(1.0-prob[i]);
            i++;
        }
        return P;
    }
    
    void combinations(vector<vector<int>> &v, int target, vector<int> &v2, vector<double>& prob){
        if(target==0){
            v.push_back(v2);
            return;
        }
        
        if(v2.size()==0){
            for(int i=0;i<=prob.size()-1-(target-1);i++){
                v2.push_back(i);
                combinations(v,target-1,v2,prob);
                v2.pop_back();
            }
        }
        
        else{
            for(int i=v2[v2.size()-1]+1;i<=prob.size()-1-(target-1);i++){
                v2.push_back(i);
                combinations(v,target-1,v2,prob);
                v2.pop_back();
            }
        }
    }
};
*/
