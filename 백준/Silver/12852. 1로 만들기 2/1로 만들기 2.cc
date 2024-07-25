#include <bits/stdc++.h>
using namespace std;
#define MAX_N 1000001
const int INF = 9e8;
int N;
int dp[MAX_N];

void trace(int n) {
	if (n == 0) return;
	cout << n << " ";
	if ((n % 3 == 0) && (dp[n] == dp[n / 3] + 1)) trace(n / 3);
	else if ((n % 2 == 0) && (dp[n] == dp[n / 2] + 1)) trace(n / 2);
	else trace(n - 1);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    
    memset(dp, INF, sizeof(dp));
    dp[1] = 0;
    for(int i = 2; i <= N; i++){
        dp[i] = i;
        if(i % 3 == 0) dp[i] = min(dp[i], dp[i / 3] + 1);
        if(i % 2 == 0) dp[i] = min(dp[i], dp[i / 2] + 1);
        dp[i] = min(dp[i], dp[i - 1] + 1);
    }
    
    cout << dp[N] << "\n";
    trace(N);
    return 0;
}
