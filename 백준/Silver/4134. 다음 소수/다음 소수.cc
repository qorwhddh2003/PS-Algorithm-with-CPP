#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 4 * 1e9;
ll t, n;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> t;
    while(t--){
        cin >> n;
        
        if(n <= 2){
            cout << 2 << "\n";
            continue;
        }
        
        for(ll i = n;; i++){
            bool flag = true;
            for(int j = 2; j < sqrt(i) + 1; j++){
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
