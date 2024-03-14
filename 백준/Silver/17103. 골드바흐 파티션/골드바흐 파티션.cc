#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e6;
int t, n, ret;
bool isPrime[MAX + 1];
vector<int> prime_numbers;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    
    fill(isPrime, isPrime + MAX + 1, 1);
    isPrime[1] = false;
    for(int i = 2; i * i <= MAX; i++){
        if(!isPrime[i]) continue;
        for(int j = i * i; j <= MAX; j += i){
            isPrime[j] = false;
        }
    }
    
    cin >> t;
    while(t--){
        cin >> n;
        ret = 0;
        for(int i = 0; i <= n / 2; i++){
            if(isPrime[i] && isPrime[n - i]){
                ret++;
            }
        }
        cout << ret << "\n";
    }
    
    return 0;
}