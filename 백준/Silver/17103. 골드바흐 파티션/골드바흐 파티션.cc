#include <bits/stdc++.h>
using namespace std;

const int MAX = 1000000;
int T, n;
bool is_prime[MAX + 1];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    
    is_prime[1] = true;
    for(int i = 2; i * i < MAX + 1; i++){
        if(is_prime[i]) continue;
        for(int j = i * i; j < MAX + 1; j += i){
            is_prime[j] = true;
        }
    }
    
    cin >> T;
    while(T--){
        cin >> n;
        int ret = 0;
        for(int i = 1; i <= n / 2; i++){
            if(!is_prime[i] && !is_prime[n - i]){
                ret++;
            }
        }
        cout << ret << "\n";
    }
    return 0;
}
