#include <bits/stdc++.h>
using namespace std;

int T;
string s;
int main(){
    cin >> T;
    while(T--){
        cin >> s;
        bool flag = 0;
        stack<char> stk;
        for(char c : s){
            if(c == '('){
                stk.push('(');
            }else{
                if(stk.size()) stk.pop();
                else{
                    flag = 1;
                    break;
                }
            }
        }
        if(flag == 1 || stk.size()) cout << "NO\n";
        else cout << "YES\n";
    }
    return 0;
}