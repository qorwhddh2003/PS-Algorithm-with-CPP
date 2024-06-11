#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll T, n;
ll dp[10001];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    
    dp[0] = 1;
    for(int i = 1; i <= 3; i++){
        for(int j = 1; j <= 10000; j++){
            if(j - i >= 0) dp[j] += dp[j - i];
        }
    }
    
    cin >> T;
    while(T--){
        cin >> n;
        cout << dp[n] << "\n";
    }

    return 0;
}