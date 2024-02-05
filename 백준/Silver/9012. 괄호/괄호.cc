#include <bits/stdc++.h>
using namespace std;

int T;
string s;

bool check(string s){
    stack<char> stk;
    for(char c : s){
        if(c == '(') stk.push('(');
        else{
            if(stk.size()) stk.pop();
            else return false;
        }
    }
    return stk.empty();
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    cin >> T;
    while(T--){
        cin >> s;
        if(check(s)) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}