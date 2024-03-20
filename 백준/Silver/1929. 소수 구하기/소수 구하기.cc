#include <bits/stdc++.h>
using namespace std;

const int MAX = 1000001;
int m, n;
bool is_prime[MAX];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> m >> n;
    
    is_prime[1] = true;
    for(int i = 2; i * i < MAX; i++){
        if(is_prime[i]) continue;
        for(int j = i * i; j < MAX; j += i){
            is_prime[j] = true;
        }
    }
    
    for(int i = m; i <= n; i++){
        if(is_prime[i]) continue;
        cout << i << "\n";
    }
    
    return 0;
}
