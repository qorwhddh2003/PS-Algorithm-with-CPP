#include <bits/stdc++.h>
using namespace std;

int k, n, ret;
stack<int> stk;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> k;
    while(k--){
        cin >> n;
        if(n == 0){
            stk.pop();
        }else{
            stk.push(n);
        }
    }
   
    while(stk.size()){
        ret += stk.top();
        stk.pop();
    }
    
    cout << ret;
    return 0;
}