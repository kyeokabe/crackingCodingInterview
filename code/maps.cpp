#include <iostream>
#include <stdio.h>
#include <stack>
#include <queue>
#include <map>
using namespace std;

int main(){
    
    map<string,int> wee;
    map<string,int>::iterator it1;
    wee["bob"]=5;
    wee["mac"]=2;

    it1=wee.find("bob");
    
    cout<<endl;
    cout<<"first item: "<<it1->first<<endl;
    cout<<"second item: "<<it1->second<<endl;
    cout<<"it1->first address: "<<&it1->first<<endl;
    cout<<"it1->second address: "<<&it1->second<<endl;
    cout<<"first it address: "<<&it1<<endl<<endl;

    it1=wee.find("mac");

    cout<<"first item: "<<it1->first<<endl;
    cout<<"second item: "<<it1->second<<endl;
    cout<<"it1->first address: "<<&it1->first<<endl;
    cout<<"it1->second address: "<<&it1->second<<endl;
    cout<<"updated it address: "<<&it1<<endl<<endl;
    
    return 0;
}
