class Solution {
private:
    multiset<int> s;
    multiset<int>::iterator it;
    
    
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double> ans;
        int ptr1=0;
        while(k>0){
            s.insert(nums[ptr1]);
            ptr1++;
            k--;
        }
        int ptr2=0;
        it=s.begin();
        int i=(s.size()-1)/2;
        while(i>0){
            it++;
            i--;
        }
        
        //cout<<"foo"<<endl;
        //cout<<"s size = "<<s.size()<<", *it = "<<*it<<endl;
        while(ptr1<nums.size()){
            cout<<"*it = "<<*it<<endl;
            if(s.size()%2==1)
                ans.push_back(double(*it));
            else
                ans.push_back(double(*it+*next(it))/2);
            int current=*it;
            s.insert(nums[ptr1]);
            int newnumber=nums[ptr1];
            pointerMod(current,newnumber);
            cout<<"test"<<endl;
            int target=nums[ptr2];
            int median=*it;
            auto it2=s.find(nums[ptr2]);
            while(it2!=s.end()&&*next(it2)==*it2)
                it2=next(it2);
            cout<<"test2"<<endl;
            s.erase(it2);
            cout<<"test3"<<endl;
            pointerMod2(target,median);
            cout<<"test4"<<endl;
            ptr1++;
            ptr2++;
        }
        
        
        if(s.size()%2==1)
            ans.push_back(double(*it));
        else
            ans.push_back(double(*it+*next(it))/2);
        
        return ans;
    }
    
    void pointerMod(int current,int &newnumber){
        if(s.size()%2==0&&current<=newnumber){
            //do nothing
        }
        else if(s.size()%2==0&&current>newnumber)
            it--;
        else if(s.size()%2==1&&current<=newnumber)
            it++;
        else{
            //do nothing
        }
    }
    
    void pointerMod2(int &target,int &median){
        if(s.size()%2==0&&median>target){
            //do nothing
        }
        else if(s.size()%2==0&&median<=target)
            it--;
        else if(s.size()%2==1&&median>target){
            it++;
        }
    }

};
