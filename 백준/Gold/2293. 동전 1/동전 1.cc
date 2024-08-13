#include <bits/stdc++.h>
using namespace std;

#define MAX_N 10001
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
    
    dp[0] = 1;
    for(int i = 0; i < N; i++){
        for(int j = 1; j <= K; j++){
            if(j < coin[i]) continue;
            dp[j] = dp[j] + dp[j - coin[i]];
        }
    }
    cout << dp[K];
    return 0;
}