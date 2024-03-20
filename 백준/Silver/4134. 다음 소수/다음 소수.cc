#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll T, n;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> T;
    while(T--){
        cin >> n;
        if(n <= 2){
            cout << 2 << "\n";
            continue;
        }
        for(ll i = n;; i++){
            bool flag = true;
            for(ll j = 2; j * j <= i; j++){
                if(i % j == 0){
                    flag = false;
                    break;
                }
            }
            if(flag){
                cout << i << "\n";
                break;
            }
        }
    }
    
    return 0;
}
