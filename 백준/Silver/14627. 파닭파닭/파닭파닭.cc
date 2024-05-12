#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll S, C, L, lo = 1, hi, ret;
ll a[1000000];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    cin >> S >> C;
    for(int i = 0; i < S; i++){
        cin >> a[i];
        hi = max(a[i], hi);
    }
    
    while(lo <= hi){
        ll mid = (lo + hi) / 2;
        ll cnt = 0, tot = 0;
        for(int i = 0; i < S; i++){
            if(cnt < C){
                cnt += a[i] / mid;
                tot += a[i] % mid;
                if(cnt > C){
                    tot += (mid * (cnt - C));
                    cnt = C;
                }
            }else{
                tot += a[i];   
            }
        }
        
        if(C == cnt){
            ret = tot;
            lo = mid + 1;
        }else hi = mid - 1;;
    }
    
    cout << ret;
    return 0;
}