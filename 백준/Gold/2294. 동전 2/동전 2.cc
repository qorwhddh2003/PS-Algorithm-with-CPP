#include <bits/stdc++.h>
using namespace std;
#define MAX_N 100001
const int INF = 9e8;
int N, K;
int dp[MAX_N];
int coin[100];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> K;
    for(int i = 0; i < N; i++) cin >> coin[i];
    fill(dp, dp + MAX_N, INF);
    
    dp[0] = 0;
    for(int i = 1; i <= K; i++){
        for(int j = 0; j < N; j++){
            if(i < coin[j]) continue;
            dp[i] = min(dp[i], dp[i - coin[j]] + 1);
        }
    }
    
    cout << (dp[K] == INF ? -1 : dp[K]);
    return 0;
}