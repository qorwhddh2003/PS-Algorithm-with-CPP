#include <bits/stdc++.h>
using namespace std;

const int MAX = 123456 * 2 + 1;
int n, m;
bool ok[MAX];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    
    fill(ok, ok + MAX, 1);
    ok[1] = false;
    for(int i = 2; i * i < MAX; i++){
        if(ok[i]){
            for(int j = i * i; j < MAX; j += i){
                ok[j] = false;
            }
        }
    }
    
    while(cin >> n){
        if(n == 0) break;
        int ret = 0;
        for(int i = n + 1; i <= 2 * n; i++){
            if(ok[i]){
                ret++;
            }
        }
        cout << ret << "\n";
    }
    return 0;
}
