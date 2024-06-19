#include <bits/stdc++.h>
using namespace std;
#define MAX_N 16
const int INF = 9e8;
int N;
int dp[MAX_N][1 << MAX_N], dist[MAX_N][MAX_N];

int go(int here, int visited){
    if(visited == (1 << N) - 1){
        return dist[here][0] ? dist[here][0] : INF;
    }
    
    int &ret = dp[here][visited];
    if(~ret) return ret;
    
    ret = INF;
    for(int i = 0; i < N; i++){
        if(visited & (1 << i)) continue;
        if(dist[here][i] == 0) continue;
        ret = min(ret, go(i, visited | (1 << i)) + dist[here][i]);
    }
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> dist[i][j];
        }
    }
    memset(dp, -1, sizeof(dp));
    cout << go(0, 1);
    return 0;
}