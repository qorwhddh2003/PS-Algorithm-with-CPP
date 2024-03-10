#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll n, temp, ret;
stack<pair<ll, ll>> stk;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> temp;
        ll cnt = 1;
        while(stk.size() && stk.top().first <= temp){
            ret += stk.top().second;
            if(stk.top().first == temp){
                cnt = stk.top().second + 1;
            }else{
                cnt = 1;
            }
            stk.pop();
        }
        if(stk.size()) ret++;
        stk.push({temp, cnt});
    }
    cout << ret;
    return 0;
}
