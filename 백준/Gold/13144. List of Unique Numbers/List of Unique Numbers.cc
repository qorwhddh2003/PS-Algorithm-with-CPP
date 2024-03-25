#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, s, e, ret;
ll cnt[100000], a[100000];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    
    while(e < n){
        if(cnt[a[e]]){
            ret += (e - s);
            cnt[a[s]]--;
            s++;
        }else{
            cnt[a[e]]++;
            e++;
        }
    }
    ret += (e - s + 1) * (e - s) / 2;
    cout << ret;
    return 0;
}
