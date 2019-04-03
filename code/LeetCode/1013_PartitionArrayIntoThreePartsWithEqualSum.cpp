/*

*/
class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& A) {
        
        bool condition1=false;
        bool condition2=false;
        
        if (A.size()<=2)
            return false;
        vector<long int> sumFront;
        int temp=0;
        for (int i=0;i<A.size();i++){
            temp+=A[i];
            sumFront.push_back(temp);
        }
        
        vector<long int> sumBack;
        int temp2=0;
        for (int i=A.size()-1;i>=0;i--){
            temp2+=A[i];
            sumBack.push_back(temp2);
            //cout<<temp2<<endl;
        }
        
        
        for (int i=0;i<A.size()/2;i++){
            long int temp=sumBack[i];
            sumBack[i]=sumBack[A.size()-1-i];
            sumBack[A.size()-1-i]=temp;
        }
        
        //for (int i=0;i<A.size();i++)
        //  cout<<sumBack[i]<<endl;
        int cond1_ind=0;
        int cond2_ind=0;
        for (int i=0;i<A.size()-2;i++)
            if (2*sumFront[i]==sumBack[i+1]){
                cout<<"cond1 true at ind = "<<i<<endl;
                cond1_ind=i;
                condition1=true;
                break;
            }
        for (int i=A.size()-1;i>1;i--)
            if(2*sumBack[i]==sumFront[i-1]){
                cout<<"cond2 true at ind = "<<i<<endl;
                cond2_ind=i;
                condition2=true;
                break;
            }
        
        /*
        cout<<"A[i] = ";
        for (int i=0;i<A.size();i++)
            cout<<A[i]<<",";
        cout<<endl;
        
        cout<<"f[i] = ";
        for (int i=0;i<A.size();i++)
            cout<<sumFront[i]<<",";
        cout<<endl;
        
        cout<<"b[i] = ";
        for (int i=0;i<A.size();i++)
            cout<<sumBack[i]<<",";
        cout<<endl;
        */
        
        return condition1&&condition2&&(cond1_ind<cond2_ind);
    }
};
