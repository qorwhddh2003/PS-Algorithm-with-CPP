#include <bits/stdc++.h>
using namespace std;

const int MAX = 1000001;
int n, m;
bool isPrime[MAX];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    fill(isPrime, isPrime + MAX, 1);
    isPrime[1] = false;
    for(int i = 2; i * i <= m; i++){
        if(isPrime[i]){
            for(int j = i * i; j <= m; j += i){
                isPrime[j] = false;
            }
        }
    }
    
    for(int i = n; i <= m; i++){
        if(isPrime[i]){
            cout << i << "\n";
        }
    }
    
    return 0;
}
