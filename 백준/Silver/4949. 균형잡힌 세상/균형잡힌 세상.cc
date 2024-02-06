#include <bits/stdc++.h>
using namespace std;

string s;

bool check(string s){
    stack<char> stk;
    for(char c : s){
        if(c == '(' || c == '[') stk.push(c);
        else if(c == ')'){
            if(stk.size() && stk.top() == '(') stk.pop();
            else return false;
        }else if(c == ']'){
            if(stk.size() && stk.top() == '[') stk.pop();
            else return false;
        }
    }
    return stk.empty();
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    while(true){
        getline(cin, s);
        if(s == ".") break;
        cout << (check(s) ? "yes\n" : "no\n");
    }
    return 0;
}