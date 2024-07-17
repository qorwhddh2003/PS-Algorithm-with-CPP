#include <bits/stdc++.h>
using namespace std;
#define MAX_N 31
typedef long long ll;
ll N;
ll dp[MAX_N][MAX_N];

ll go(int w, int h){
    if(w == 0 && h == 0) return 1;
    ll &ret = dp[w][h];
    if(ret) return ret;
    if(w > 0) ret += go(w - 1, h + 1);
    if(h > 0) ret += go(w, h - 1);
    return ret;    
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    while(cin >> N){
        if(N == 0) break;
        cout << go(N, 0) << "\n"; 
    }

    return 0;
}

