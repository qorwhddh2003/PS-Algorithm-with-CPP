#include <bits/stdc++.h>
using namespace std;
#define MAX_N 1000001
const int INF = 9e8;
int N;
int dp[MAX_N];


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    
    for(int i = 1; i <= N; i++){
        dp[i] = i;
        if(i % 3 == 0) dp[i] = min(dp[i], dp[i / 3] + 1);
        if(i % 2 == 0) dp[i] = min(dp[i], dp[i / 2] + 1);
        dp[i] = min(dp[i], dp[i - 1] + 1);
    }
    
    cout << dp[N] - 1 << "\n";
    cout << N << " ";
    while(true){
        --dp[N];
        if(!dp[N]) break;
        if(N % 3 == 0 && dp[N / 3] == dp[N]){
            cout << N / 3;
            N /= 3;
        }else if(N % 2 == 0 && dp[N / 2] == dp[N]){
            cout << N / 2;
            N /= 2;
        }else{
            cout << N - 1;
            N -= 1;
        }
        cout << " ";
    }
    return 0;
}
