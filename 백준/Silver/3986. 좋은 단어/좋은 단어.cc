#include <bits/stdc++.h>
using namespace std;

int n, ret;
string str;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin >> n;
    
    while(n--){
        stack<char> stk;
        cin >> str;
        for(char c : str){
            if(stk.empty()) stk.push(c);
            else if(stk.top() == c) stk.pop();
            else if(stk.top() != c) stk.push(c);
        }
        if(stk.empty()) ret++;
    }
    
    cout << ret;
    return 0;
}