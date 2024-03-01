#include <bits/stdc++.h>
using namespace std;

int n, ret;
string s;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> s;
    
    stack<int> stk;
    stk.push(-1);
    for(int i = 0; i < n; i++){
        if(s[i] == '(') stk.push(i);
        else{
            stk.pop();
            if(stk.size()) ret = max(ret, i - stk.top());
            else stk.push(i);
        }
    }
    
    cout << ret;
    return 0;
}