class Solution {
public:
    int maxLength(vector<string>& arr) {
        //take care of trivial cases
        if(arr.size()==0)
            return 0;
        if(arr.size()==1)
            return arr[0].length();
        
        //delete inputs with same char
        for(int i=0;i<arr.size();i++)
            if(!isUnique(arr[i])){
                swap(arr[i],arr[arr.size()-1]);
                arr.pop_back();
                i--;
            }
        
        list<int> v1;
        for(int i=0;i<arr.size();i++){
            int temp=0;
            for(int j=0;j<arr[i].length();j++){
                temp+=(1<<arr[i][j]-97);//maps a->2^0, b->2^1,...z->2^26
            }
            v1.push_back(temp);
        }
                
        list<int> v2;
        v2.push_back(0);
        int ans=0;
        
        for(auto ptr1=v1.begin();ptr1!=v1.end();ptr1++){
            for(auto ptr2=v2.begin();ptr2!=v2.end();ptr2++){
                int bit_w_and=(*ptr1&*ptr2);
                if(bit_w_and==0){
                    int sum=*ptr1+*ptr2;
                    v2.push_back(sum);
                    int count=0;
                    while(sum>0){
                        if(sum%2==1)
                            count++;
                        sum=(sum>>1);
                    }
                    count>ans?ans=count:ans=ans;
                }
            }
        }
        return ans;
    }
    
    bool isUnique(string s){
        if(s.length()>27)
            return false;
        vector<int> v(26,0);
        for(int i=0;i<s.length();i++){
            v[s[i]-97]++;
            if(v[s[i]-97]>1)
                return false;
        }
        return true;
    }


};

/*
class Solution {
public:
    int maxLength(vector<string>& arr) {
        int ans=1;
        for(int i=0;i<arr.size();i++){
            for(int j=i;j<arr.size();j++){
                vector<int> v(26,0);
                for(int k=0;k<arr[j].size();k++)
                    v[arr[j][k]-97]++;
                
                bool containsdup=false;
                int charcount=0;
                for(int k=0;k<v.size();k++){
                    if(v[k]>1)
                        containsdup=true;
                    if(v[k]==1)
                        charcount++;
                }
                if(!containsdup&&charcount>ans){
                    ans=charcount;
                }
                else{
                    for(int k=0;k<arr[j].size();k++)
                        v[arr[j][k]-97]--;
                }
            }
        }
        return ans;
    }
};
*/
