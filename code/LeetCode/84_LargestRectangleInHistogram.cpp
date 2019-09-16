//adapted from
//https://www.youtube.com/watch?v=VNbkzsnllsU

class Solution {
public:
    int largestRectangleArea(vector<int>& v) {
        //v.push_back(0);
        stack<int> h;
        stack<int> i;
        int ans=0;
        
        for(int j=0;j<v.size();j++){
            if(h.empty()){
                h.push(v[j]);
                i.push(j);
            }
            else{
                if(h.top()<v[j]){
                    h.push(v[j]);
                    i.push(j);
                }
                else {
                    int temp=INT_MIN;
                    while(!h.empty()&&h.top()>=v[j]){
                        int area=h.top()*(j-i.top());
                        if(area>ans)
                            ans=area;
                        h.pop();
                        temp=i.top();
                        i.pop();
                    }
                    h.push(v[j]);
                    if(temp==INT_MIN)
                        i.push(j);
                    else
                        i.push(temp);
                }
            }
        }
        
        while(!h.empty()){
            int area=h.top()*(v.size()-i.top());
            if(ans<area)
                ans=area;
            h.pop();
            i.pop();
        }
        
        return ans;
    }
};
