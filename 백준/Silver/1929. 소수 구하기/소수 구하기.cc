#include <bits/stdc++.h>
using namespace std;

int n, m;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    for(int i = n; i <= m; i++){
        if(i <= 1){
            continue;
        }
        
        bool flag = true;
        for(int j = 2; j * j <= i; j++){
            if(i % j == 0){
                flag = false;
                break;
            }
        }
        if(flag){
            cout << i << "\n";
        }
    }
    
    return 0;
}
