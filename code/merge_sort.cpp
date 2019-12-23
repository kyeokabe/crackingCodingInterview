
vector<int> sort(vector<int> &v);
vector<int> merge(vector<int> &v1, vector<int> &v2);
int main() {
    vector<int> v={6,7,8,3,2,5,6};    
    vector<int> ans=sort(v);
    for(int i=0;i<ans.size();i++)
        cout<<ans[i]<<", ";
    cout<<" "<<endl;
    return 0;
}

vector<int> sort(vector<int> &v){
    if(v.size()==1)
        return v;
    int HALF;
    if(v.size()%2==0)
        HALF=v.size()/2;
    else
        HALF=v.size()/2+1;
    vector<int> v1(v.begin(),v.begin()+HALF);
    vector<int> v2(v.begin()+HALF,v.end());
    v1=sort(v1);
    v2=sort(v2);
    return merge(v1,v2);
}

vector<int> merge(vector<int> &v1,vector<int> &v2){
    
    int i=0;
    int j=0;
    vector<int> v;
    v.reserve(v1.size()+v2.size());
    while(i<v1.size()&&j<v2.size()){
        if(v1[i]<v2[j]){
            v.push_back(v1[i]);
            i++;
        }
        else{
            v.push_back(v2[j]);
            j++;
        }
    }
    
    while(i<v1.size()){
        v.push_back(v1[i]);
        i++;
    }
    while(j<v2.size()){
        v.push_back(v2[j]);
        j++;
    }
    return v;
}
