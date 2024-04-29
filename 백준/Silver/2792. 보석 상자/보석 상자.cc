#include <bits/stdc++.h>
using namespace std;
#define left aaa
typedef long long ll;

ll N, M, K, left = 1, high, ret = 1e18;
ll a[300000];

bool check(ll mid){
    ll num = 0;
    for(int i = 0; i < M; i++){
        num += a[i] / mid;
        if(a[i] % mid) num++;
    }
    return  N >= num;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M;
    for(int i = 0; i < M; i++){
        cin >> a[i];
        high = max(high, a[i]);
    }
    
    while(left <= high){
        ll mid = (left + high) / 2;
        if(check(mid)){
            ret = min(ret, mid);
            high = mid - 1;
        }else left = mid + 1;
    }
    
    cout << ret;
    return 0;
}
