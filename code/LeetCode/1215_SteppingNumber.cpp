class Solution {
public:
    vector<int> countSteppingNumbers(int low, int high) {
        
        vector<int> ans;
        unordered_map<int,int> m;

        if(0>=low&&0<=high){
            ans.push_back(0);
            m[0]++;
        }
        queue<int> q;
        q.push(1);
        q.push(2);
        q.push(3);
        q.push(4);
        q.push(5);
        q.push(6);
        q.push(7);
        q.push(8);
        q.push(9);
        
        while(!q.empty()){
            if(q.front()>=low&&q.front()<=high&&m.find(q.front())==m.end()){
                ans.push_back(q.front());
                m[q.front()]++;
            }
            
            int smallest=q.front()%10;//get first digit of current number
  
            if(smallest+1<=9){
                if(INT_MAX/10>q.front()||(INT_MAX/10==q.front()&&INT_MAX%10>=smallest+1)){
                    int temp=q.front()*10+smallest+1;
                    q.push(temp); 
                }
            }
            if(smallest-1>=0){
                if(INT_MAX/10>q.front()||(INT_MAX/10==q.front()&&INT_MAX%10>=smallest-1)){
                    int temp=q.front()*10+smallest-1;
                    q.push(temp);  
                }
            }
            q.pop();
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};
