//based on discussions, could have used two pointers for a 1 pass solution
//000100100100
//check i) distance to first 1 from beginning
//check ii) max distance/2 between 1s
//check iii) distance from last 1 to end
class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        vector<int> L(seats.size(),0);
        vector<int> R(seats.size(),0);
        
        int ans=0;
        
        bool persontoL=true;        
        if(seats[0]==0){
            L[0]=INT_MAX;
            persontoL=false;
        }
        for(int i=1;i<seats.size();i++){
            if(persontoL==false&&seats[i]==0)
                L[i]=INT_MAX;
            if(seats[i]==1){
                L[i]=0;
                persontoL=true;
            }
            if(persontoL==true&&seats[i]==0)
                L[i]=L[i-1]+1;
        }
        
        bool persontoR=true;        
        if(seats[seats.size()-1]==0){
            R[seats.size()-1]=INT_MAX;
            persontoR=false;
        }
        for(int i=seats.size()-2;i>=0;i--){
            if(persontoR==false&&seats[i]==0)
                R[i]=INT_MAX;
            if(seats[i]==1){
                R[i]=0;
                persontoR=true;
            }
            if(persontoR==true&&seats[i]==0)
                R[i]=R[i+1]+1;
        }
        
        for(int i=0;i<seats.size();i++)
            if(min(L[i],R[i])>ans)
                ans=min(L[i],R[i]);
        return ans;
    }
};
