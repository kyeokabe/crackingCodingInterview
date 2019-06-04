class Solution {
public:
    int nextGreaterElement(int n) {
        int original=n;
        stack<int> s;
        
        while(n!=0){
            s.push(n%10);
            n=n/10;
        }
        
        vector<int> v;
        while(!s.empty()){
            v.push_back(s.top());
            s.pop();
        }

        next_permutation(v.begin(), v.end());
        
        long long ans=0;
                
        for(int i=0;i<v.size();i++){
            ans+=v[v.size()-1-i]*pow(10,i);
        }
        //cout<<"ans = "<<ans<<endl;
        //cout<<"n = "<<n<<endl;

        return (ans > INT_MAX || ans <= original) ? -1 : ans;
    }
};
