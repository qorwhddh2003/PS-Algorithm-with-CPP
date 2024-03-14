#include <bits/stdc++.h>
using namespace std;

int t, n, number = 1;
stack<int> stk;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> t;
    while(t--){
        cin >> n;
        stk.push(n);
        while(stk.size() && stk.top() == number){
            number++;
            stk.pop();
        }
    }
    if(stk.size()) cout << "Sad";
    else cout << "Nice";
    return 0;
}