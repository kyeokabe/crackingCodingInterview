//1.5 One Away
/*
 There are three types of edits that can be performed on strings:
 Insert a char, remove a char, or replace a char.
 
 Given two strings, write a function to check if they are one edit
 or zero edits away.

 
*/

#include <iostream>
#include <stdio.h>
#include <stack>
#include <queue>
using namespace std;


bool OneAwayy(string a, string b);
bool IsSwapChar(string a, string b);
bool IsDelChar(string a, string b);

int main(){
    
    string foo1="poop";
    string foo2="peeps";
    
    bool OneAway=false;
    //cout<<foo1[3]<<endl;
    //OneAway=OneAwayy(foo1,foo2);
    
    return 0;
}

bool OneAwayy(string a, string b){
    
    if (a==b)
        return true;
    
    if (a.length()>b.length()+1 || a.length()+1<b.length())
        return false;
    
    bool check1=IsSwapChar(a,b);
    bool check2;
    return false;
}

bool IsSwapChar(string a,string b){
    int count=0;
    for (int i=a.length();i<a.length();i++){
        if (a[i]!=b[i])
            count++;
    }
    if (count>=2)
        return false;
    return true;
}

//a must be larger than b
bool IsDelChar(string a, string b){
    
    string temp;
    
    
    for (int i=0; i<a.length();i++){
        
    }
    
    return false;
}
