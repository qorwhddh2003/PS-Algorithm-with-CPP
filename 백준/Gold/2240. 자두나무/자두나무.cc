#include <bits/stdc++.h>
using namespace std;

int T, W;
int a[1000], dp[1000][2][30];

void fastIO(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
}

int go(int idx, int loc, int cnt){ // idx: 시간, loc: 위치, cnt: 이동 회수
    if(cnt < 0) return -1e9;
    if(idx == T) return (cnt == 0 ? 0 : -1e9);
    
    int &ret = dp[idx][loc][cnt];
    if(~ret) return ret;
    
    return ret = max(go(idx + 1, loc, cnt), go(idx + 1, loc ^ 1, cnt - 1)) + (a[idx] - 1 == loc);
}

int main()
{
    fastIO();
    memset(dp, -1, sizeof(dp));
    cin >> T >> W;
    for(int i = 0; i < T; i++) cin >> a[i];
    cout << max(go(0, 0, W), go(0, 1, W - 1));
    return 0;
}
