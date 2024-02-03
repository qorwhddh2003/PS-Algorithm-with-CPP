#include <bits/stdc++.h>
using namespace std;

int n, ret;
string s;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin >> n;
    for(int i = 0; i < n; i++){
        stack<char> stk;
        cin >> s;
        
        for(char c : s){
            if(stk.size() != 0 && stk.top() == c) stk.pop();
            else stk.push(c);
        }
        
        if(stk.size() == 0) ret++; 
    }
    
    cout << ret;
    return 0;
}
