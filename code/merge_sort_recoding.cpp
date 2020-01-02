
vector<int> mergesort(vector<int> &v){
    if(v.size()<=1)
        return v;
    int HALF;
    if(v.size()%2==0)
        HALF=v.size()/2;
    else
        HALF=v.size()/2+1;
    vector<int> v1(v.begin(),v.begin()+HALF);
    vector<int> v2(v.begin()+HALF,v.end());
    v1=mergesort(v1);
    v2=mergesort(v2);
    int i1=0;
    int i2=0;
    vector<int> x;
    x.reserve(v.size());
    while(i1<v1.size()&&i2<v2.size()){
        if(v1[i1]<v2[i2]){
            x.push_back(v1[i1]);
            i1++;
        }
        else{
            x.push_back(v2[i2]);
            i2++;
        }
    }
        
    while(i1<v1.size()){
        x.push_back(v1[i1]);
        i1++;
    }
    while(i2<v2.size()){
        x.push_back(v2[i2]);
        i2++;
    }
    return x;
}


int main() {
    
    vector<int> v={1};
    vector<int> ans=mergesort(v);
    for(int i=0;i<ans.size();i++)
        cout<<ans[i]<<" "<<endl;
    return 0;
}
