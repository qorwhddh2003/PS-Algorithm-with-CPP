#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll a, b, c;

ll go(ll a, ll b){
    if(b == 1) return a % c;
    
    ll ret = go(a, b / 2);
    ret = (ret * ret) % c;
    if(b & 1) ret *= a % c;
    return ret % c;
}

int main(){
    cin >> a >> b >> c;
    cout << go(a, b);
    return 0;
}