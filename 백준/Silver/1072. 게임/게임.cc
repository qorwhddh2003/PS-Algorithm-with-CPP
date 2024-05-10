#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll X, Y, Z, lo = 1, hi = 1e9, ret = -1;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    cin >> X >> Y;
    Z = (Y * 100 / X);
    while(lo <= hi){
        ll mid = (lo + hi) / 2;
        ll per = ((Y + mid) * 100) / (X + mid);
        if(Z == per){
            lo = mid + 1;
        }else{
            ret = mid;
            hi = mid - 1;
        }
    }
    cout << ret;
    return 0;
}