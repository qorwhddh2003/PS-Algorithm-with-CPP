#include <string>
#include <stack>
#include <iostream>
#include <algorithm>

using namespace std;

bool check(string u){
    stack<char> stk;
    for(int i = 0; i < u.size(); i++){
        if(u[i] == '(') stk.push('(');
        else{
            if(stk.size()) stk.pop();
            else return false;
        }
    }
    return true;
}

string go(string str){
    if(str == "") return "";    
    int i = 0, cnt1 = 0, cnt2 =0;
    for(i = 0; i < str.size(); i++){
        if(str[i] == '(') cnt1++;
        else cnt2++;
        if(cnt1 == cnt2) break;
    }
        
    string u = str.substr(0, i + 1);
    string v = str.substr(i + 1);
    
    if(check(u)){
        return u + go(v);
    }else{
        string temp = "(";
        temp += go(v);
        temp += ")";
        string rev = u.substr(1, u.size() - 2);       
        for(int i = 0; i < rev.size(); i++){
            if(rev[i] == '(') temp += ')';
            else temp += '(';
        }
        return temp;
    }
    
    return u;
}

string solution(string p) {        
    string ret = go(p);    
    return ret;
}