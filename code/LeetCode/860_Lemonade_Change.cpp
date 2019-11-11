class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int Five=0;
        int Ten=0;
        
        for(int i=0;i<bills.size();i++){
            if(bills[i]==5)
                Five++;
            else if(bills[i]==10){
                if(Five<=0)
                    return false;
                else{
                    Five--;
                    Ten++;
                }
            }
            else{
                if(Ten>0){
                    Ten--;
                    if(Five>0){
                        Five--;
                    }
                    else
                        return false;
                }
                else if(Five>=3){
                    Five=Five-3;
                }
                else
                    return false;
            }
        }
        
        return true;
        
    }
};
